#include "sofautils.h"
#include <algorithm>
#include <cassert>
#include <cmath>
#include <fstream>
#include <tuple>
#include <utility>
#include <vector>

namespace {
double cross(std::pair<double, double> v1, std::pair<double, double> v2) {
    return v1.first * v2.second - v1.second * v2.first;
}

// Reference:
// https://cp-algorithms.com/geometry/check-segments-intersection.html
bool inter1(double a, double b, double c, double d) {
    if (a > b)
        std::swap(a, b);
    if (c > d)
        std::swap(c, d);
    return std::max(a, c) <= std::min(b, d);
}

// Reference:
// https://cp-algorithms.com/geometry/check-segments-intersection.html
inline int sgn(const double &x) { return x > 1e-6 ? 1 : x < -1e-6 ? -1 : 0; }

// Reference:
// https://cp-algorithms.com/geometry/check-segments-intersection.html
bool line_intersects_line(
    std::pair<std::pair<double, double>, std::pair<double, double>> l1,
    std::pair<std::pair<double, double>, std::pair<double, double>> l2) {
    std::pair<double, double> a, b, c, d;
    std::tie(a, b) = l1;
    std::tie(c, d) = l2;
    if (std::abs(cross({a.first - c.first, a.second - c.second},
                       {d.first - c.first, d.second - c.second})) < 1e-6 &&
        std::abs(cross({b.first - c.first, b.second - c.second},
                       {d.first - c.first, d.second - c.second})) < 1e-6)
        return inter1(a.first, b.first, c.first, d.first) &&
               inter1(a.second, b.second, c.second, d.second);
    return sgn(cross({b.first - a.first, b.second - a.second},
                     {c.first - a.first, c.second - a.second})) !=
               sgn(cross({b.first - a.first, b.second - a.second},
                         {d.first - a.first, d.second - a.second})) &&
           sgn(cross({d.first - c.first, d.second - c.second},
                     {a.first - c.first, a.second - c.second})) !=
               sgn(cross({d.first - c.first, d.second - c.second},
                         {b.first - c.first, b.second - c.second}));
}

// Reference: https://wrfranklin.org/Research/Short_Notes/pnpoly.html
bool point_in_polygon(std::pair<double, double> point,
                      std::vector<std::pair<double, double>> poly) {
    int i, j, c = 0;
    int nvert = poly.size();
    for (i = 0, j = nvert - 1; i < nvert; j = i++) {
        if (((poly[i].second > point.second) !=
             (poly[j].second > point.second)) &&
            (point.first < (poly[j].first - poly[i].first) *
                                   (point.second - poly[i].second) /
                                   (poly[j].second - poly[i].second) +
                               poly[i].first))
            c = !c;
    }
    return c;
}

/**
 * Returns true if line intersects a side of the polygon, or if line
 * is inside the polygon.
 */
bool line_interacts_polygon(
    std::pair<std::pair<double, double>, std::pair<double, double>> line,
    std::vector<std::pair<double, double>> poly) {
    for (int i = 0; i < poly.size(); i++) {
        std::pair<std::pair<double, double>, std::pair<double, double>> sline =
            std::make_pair(poly[i], poly[i + 1 == poly.size() ? 0 : i + 1]);
        if (line_intersects_line(line, sline)) {
            return true;
        }
    }
    return point_in_polygon(line.first, poly) ||
           point_in_polygon(line.second, poly);
}

/**
 * @brief rotate about the origin for theta radians (ccw)
 *
 * @param pt
 * @param theta
 * @return std::pair<double, double>
 */
std::pair<double, double> rotate(std::pair<double, double> pt, double theta) {
    double ct = cos(theta);
    double st = sin(theta);
    return {pt.first * ct - pt.second * st, pt.first * st + pt.second * ct};
}

inline double plug_in_curve(const std::pair<double, double> &p,
                            const std::pair<double, double> &q,
                            const double &t) {
    double cptx = p.first + (q.first - p.first) * t;
    double cpty = p.second + (q.second - p.second) * t;
    return cptx * cptx + cpty * cpty;
}
inline double angle_in_curve(const std::pair<double, double> &p,
                             const std::pair<double, double> &q,
                             const double &t) {
    double cptx = p.first + (q.first - p.first) * t;
    double cpty = p.second + (q.second - p.second) * t;
    return atan2(cpty, cptx);
}

inline bool angle_between(double atest, double lo, double hi) {
    return lo > hi ? !(hi < atest && atest < lo) : lo <= atest && atest <= hi;
}

double bsearch_lineseg(std::pair<double, double> p, std::pair<double, double> q,
                       double r_target) {
    double lo = 0;
    double hi = 1;
    // alpha(t) = line.p1 + (line.p2 - line.p1) * t
    for (int rep = 0; rep < 32; rep++) {
        double mid = (lo + hi) / 2;
        double cur = plug_in_curve(p, q, mid);
        if (cur < r_target)
            lo = mid;
        else
            hi = mid;
    }
    return (lo + hi) / 2;
}

bool point_in_pararc(std::pair<double, double> p, std::pair<double, double> p1,
                     std::pair<double, double> p2, std::pair<double, double> p3,
                     std::pair<double, double> p4, double r1, double r2,
                     double theta) {
    double rp = p.first * p.first + p.second * p.second;
    if (rp < r1 || rp > r2)
        return false;
    double t_left = bsearch_lineseg(p1, p2, rp);
    double t_right = bsearch_lineseg(p3, p4, rp);
    double a_left = angle_in_curve(p1, p2, t_left);
    double a_right = angle_in_curve(p3, p4, t_right);
    double a = atan2(p.second, p.first);
    return angle_between(a, a_left, a_right);
}

/**
 * Returns true if line intersects a side of the pararc, or if line
 * is inside the pararc.
 */
bool line_interacts_pararc(
    std::pair<std::pair<double, double>, std::pair<double, double>> line,
    std::pair<double, double> p1, std::pair<double, double> p2, double theta) {
    if (p1.first * p1.first + p1.second * p1.second >
        p2.first * p2.first + p2.second * p2.second)
        std::swap(p1, p2);
    if (line.first.first * line.first.first +
            line.first.second * line.first.second >
        line.second.first * line.second.first +
            line.second.second * line.second.second)
        std::swap(line.first, line.second);
    double r1 = p1.first * p1.first + p1.second * p1.second;
    double r2 = p2.first * p2.first + p2.second * p2.second;
    std::pair<double, double> p3 = rotate(p1, theta);
    std::pair<double, double> p4 = rotate(p2, theta);
    if (theta < 0) {
        swap(p1, p3);
        swap(p2, p4);
        theta = -theta;
    }
    if (line_intersects_line(line, {p1, p2}))
        return true;
    if (line_intersects_line(line, {p3, p4}))
        return true;
    if (point_in_pararc(line.first, p1, p2, p3, p4, r1, r2, theta))
        return true;
    if (point_in_pararc(line.second, p1, p2, p3, p4, r1, r2, theta))
        return true;
    double rp = line.first.first * line.first.first +
                line.first.second * line.first.second;
    if (rp >= r1 && rp <= r2)
        return false;
    rp = line.second.first * line.second.first +
         line.second.second * line.second.second;
    if (rp >= r1 && rp <= r2)
        return false;
    double t1 = bsearch_lineseg(line.first, line.second, r1);
    double t2 = bsearch_lineseg(line.first, line.second, r2);
    double rt1 = plug_in_curve(line.first, line.second, t1);
    double rt2 = plug_in_curve(line.first, line.second, t2);
    assert(t1 <= t2);
    if (rt2 < r1)
        return false;
    if (rt1 > r2)
        return false;
    assert(std::abs(rt1 - r1) < 1e-6);
    assert(std::abs(rt2 - r2) < 1e-6);
    double a1 = angle_in_curve(line.first, line.second, t1);
    double a2 = angle_in_curve(line.first, line.second, t2);
    if (angle_between(a1, atan2(p1.second, p1.first),
                      atan2(p3.second, p3.first)))
        return true;
    if (angle_between(a2, atan2(p2.second, p2.first),
                      atan2(p4.second, p4.first)))
        return true;
    return false;
}
} // namespace

void ObstacleSet::read_input(std::istream &in) {
    int n;
    in >> n;
    for (int i = 0; i < n; i++) {
        double x, y;
        in >> x >> y;
        vertices.push_back({x, y});
    }
    int m;
    in >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        in >> u >> v;
        edges.push_back({u, v});
    }
}

void Sofa::read_input(std::istream &in) {
    int n;
    in >> n;
    for (int i = 0; i < n; i++) {
        double x, y;
        in >> x >> y;
        poly.push_back({x, y});
    }
}

bool Sofa::translate_sofa(const ObstacleSet &obs,
                          std::pair<double, double> direction) {
    for (int i = 0; i < poly.size(); i++) {
        std::pair<double, double> p1 = poly[i];
        std::pair<double, double> p2 = poly[i + 1 == poly.size() ? 0 : i + 1];
        std::pair<double, double> p3 = {p2.first + direction.first,
                                        p2.second + direction.second};
        std::pair<double, double> p4 = {p1.first + direction.first,
                                        p1.second + direction.second};
        // check if parallelogram (p1, p2, p3, p4) hits a line segment (i.e.
        // contain any of its endpoints)
        for (auto e : obs.edges) {
            if (line_interacts_polygon(
                    {obs.vertices[e.first], obs.vertices[e.second]},
                    {p1, p2, p3, p4})) {
                return false;
            }
        }
    }
    for (auto &p : poly) {
        p.first += direction.first;
        p.second += direction.second;
    }
    return true;
}
bool Sofa::rotate_sofa(const ObstacleSet &obs,
                       std::pair<double, double> fulcrum, double theta) {
    for (int i = 0; i < poly.size(); i++) {
        std::pair<double, double> p1 = {poly[i].first - fulcrum.first,
                                        poly[i].second - fulcrum.second};
        std::pair<double, double> p2 = poly[i + 1 == poly.size() ? 0 : i + 1];
        p2.first -= fulcrum.first;
        p2.second -= fulcrum.second;
        // check if parallelogram (p1, p2, p3, p4) hits a line segment (i.e.
        // contain any of its endpoints)
        for (auto e : obs.edges) {
            if (line_interacts_pararc(
                    {{obs.vertices[e.first].first - fulcrum.first,
                      obs.vertices[e.first].second - fulcrum.second},
                     {obs.vertices[e.second].first - fulcrum.first,
                      obs.vertices[e.second].second - fulcrum.second}},
                    p1, p2, theta))
                return false;
        }
    }
    for (auto &p : poly) {
        p.first -= fulcrum.first;
        p.second -= fulcrum.second;
        p = rotate(p, theta);
        p.first += fulcrum.first;
        p.second += fulcrum.second;
    }
    return true;
}

double Sofa::area() {
    double acc = 0.0;
    for (int i = 0; i < poly.size(); i++) {
        acc += poly[i].first * poly[i + 1 == poly.size() ? 0 : i + 1].second;
        acc -= poly[i].second * poly[i + 1 == poly.size() ? 0 : i + 1].first;
    }
    return std::abs(acc) / 2.0;
}