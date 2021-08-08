import java.io.BufferedReader
import java.io.InputStreamReader
import java.math.BigInteger
import java.util.*

fun main() = with(BufferedReader(InputStreamReader(System.`in`))){
    val (N,M) = readLine().split(' ').map{it.toInt()}
    var up = BigInteger("1")
    var down = BigInteger("1")
    for(i in 1..M){
        up = up.multiply(BigInteger((N-i+1).toString()))
        down = down.multiply(BigInteger(i.toString()))
    }
    println(up.divide(down))
}