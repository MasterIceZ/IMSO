import kotlin.math.min

private fun next() = readLine()!!
private fun nextInt() = next().toInt()
private fun nextLong() = next().toLong()
private fun nextInts() = next().split(" ").map(String::toInt)
private fun nextLongs() = next().split(" ").map(String::toLong)

fun main(args: Array<String>) {
    val t = nextInt()
    repeat(t) {
        val (n, m) = nextInts()
        if(n == 2) {
            if(m % 2 == 0) {
                print("1 2")
            }
            else {
                print("2 1")
            }
        }
        else {
            val b = min(n, m)
            for(i in n downTo n - b + 1) {
                print("$i ")
            }
            for(i in 1..(n - b)) {
                print("$i ")
            }
        }
        print("\n")
    }
}