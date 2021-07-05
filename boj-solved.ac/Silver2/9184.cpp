import java.io.BufferedReader
import java.io.InputStreamReader
import java.lang.Integer.max
import java.lang.Integer.min
import java.util.*
var dp=Array(21,{Array(21,{Array<Int>(21,{-1})})})
fun sol(n:Int,m:Int,k:Int):Int{
    when {
        (n <= 0 || m <= 0 || k <= 0) -> return 1
        (n > 20 || m > 20 || k > 20) -> return sol(20, 20, 20)
    }
    if(dp[n][m][k]!=-1) return dp[n][m][k]
    dp[n][m][k] = when{
        (n<m&&m<k)->sol(n,m,k-1)+sol(n,m-1,k-1)-sol(n,m-1,k)
        else -> sol(n-1,m,k)+sol(n-1,m-1,k)+sol(n-1,m,k-1)-sol(n-1,m-1,k-1)
    }
    return dp[n][m][k]
}
fun main() = with(BufferedReader(InputStreamReader(System.`in`))){
    while(true){
        var (N,M,K) = readLine().split(' ').map{it.toInt()}
        if(N==-1&&M==-1&&K==-1) break
        println("w($N, $M, $K) = ${sol(N,M,K)}")
    }
}