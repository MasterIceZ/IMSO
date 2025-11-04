import kotlin.math.abs

private fun next() = readLine()!!
private fun nextInt() = next().toInt()
private fun nextLong() = next().toLong()
private fun nextInts() = next().split(" ").map(String::toInt)
private fun nextLongs() = next().split(" ").map(String::toLong)

fun main(args: Array<String>) {
    val (n, a, b) = nextInts()
    println(abs(a + b - n + 1) - 1)
}