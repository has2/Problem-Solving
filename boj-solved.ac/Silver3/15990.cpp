import java.io.BufferedReader
import java.io.InputStreamReader
val mod = 1e9.toInt()+9
fun main() = with(BufferedReader(InputStreamReader(System.`in`))){
    var t = readLine().toInt()
    val dp = Array<IntArray>(4) { IntArray(100001) }
    dp[1][1]=1
    dp[2][2]=1
    dp[3][3]=1
    for(i in 1..100000){
        for(j in 1..3){
            if(i-j<0) continue
            for(k in 1..3){
                if(j!=k)
                    dp[j][i]=(dp[j][i]+dp[k][i-j])%mod
            }
        }
    }
    while(t-->0){
        val N = readLine().toInt()
        println(((dp[1][N]+dp[2][N])%mod+dp[3][N])%mod)
    }
}
