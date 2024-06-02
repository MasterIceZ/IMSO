"""
Sofa visualizer.
"""

import argparse
from matplotlib import pyplot as plt
import math

parser = argparse.ArgumentParser(
    prog='sofavis.py',
    description='Visualize the obstacles and the sofa.')
parser.add_argument('--input_filename', required=True,
                    help='the input file containing the obstacle data')
parser.add_argument('--output_filename', required=False,
                    help='the output file containing the sofa polygon')
parser.add_argument('--figure_filename', required=False,
                    help='the visualizer figure output')
args = parser.parse_args()
infname = args.input_filename
oufname = args.output_filename
fgfname = args.figure_filename

if oufname is not None:
    with open(oufname) as ouf:
        N = int(ouf.readline().strip())
        xs = []
        ys = []
        for i in range(N):
            x, y = map(float, ouf.readline().split())
            xs.append(x)
            ys.append(y)
        xs.append(xs[0])
        ys.append(ys[0])
        plt.plot(xs, ys, '--')
        M = int(ouf.readline().strip())
        for i in range(M):
            line = ouf.readline()
            if line.split()[0][0] == 'F':
                t, x, y = line.split()
            else:
                t, d, x, y = line.split()
                d = float(d) * math.pi / 180
            x = float(x)
            y = float(y)
            if t[0] == 'F':
                nxs = [ox + x for ox in xs]
                nys = [oy + y for oy in ys]
            else:
                nxs = [ox - x for ox in xs]
                nys = [oy - y for oy in ys]
                for i in range(N+1):
                    rotx = nxs[i] * math.cos(d) - nys[i] * math.sin(d)
                    roty = nxs[i] * math.sin(d) + nys[i] * math.cos(d)
                    nxs[i] = rotx + x
                    nys[i] = roty + y
            if i != 0:
                ox = sum(xs) / len(xs)
                oy = sum(ys) / len(ys)
                nx = sum(nxs) / len(nxs)
                ny = sum(nys) / len(nys)
                plt.plot([ox, nx], [oy, ny], '-')
            plt.plot(nxs, nys, '-')
            xs, ys = nxs, nys
with open(infname) as inf:
    N = int(inf.readline().strip())
    xs = []
    ys = []
    for i in range(N):
        x, y = map(float, inf.readline().split())
        xs.append(x)
        ys.append(y)
    plt.plot(xs, ys, 'o')
    M = int(inf.readline().strip())
    for i in range(M):
        u, v = map(int, inf.readline().split())
        plt.plot([xs[u], xs[v]], [ys[u], ys[v]], color='black')
    plt.plot([0, 0], [100, 110], color='black')
    plt.plot([0, 0], [110, 150], '--', color='black')
    plt.plot([0, 0], [-100, -110], color='black')
    plt.plot([0, 0], [-110, -150], '--', color='black')
    plt.axvspan(-250, -100, facecolor='r', alpha=0.5)
    plt.axvspan(100, 250, facecolor='b', alpha=0.5)
    plt.axis("equal")
    plt.xlim(-200, 200)
    plt.ylim(-150, 150)
    if fgfname is None:
        plt.show()
    else:
        plt.savefig(fgfname)
