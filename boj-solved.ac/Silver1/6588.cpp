import java.io.BufferedReader
import java.io.InputStreamReader
import java.lang.IndexOutOfBoundsException
import java.util.*
const val mxN = 1000000
fun main() = with(BufferedReader(InputStreamReader(System.`in`))){

    var list = ArrayList<Int>()
    var nP = BooleanArray(mxN+1)
    nP[1]=true

    for(i in 2..mxN/2){
        if(nP[i]) continue
        var j=i*2
        while(j<=mxN){
            nP[j]=true
            j+=i
        }
    }
    for(i in 2..mxN) {
        if(!nP[i]) list.add(i)
    }
    while(true){
        var ip = readLine().toInt()
        if(ip==0) break

        for(a in list){
            if(!nP[ip-a]){
                println("$ip = $a + ${ip-a}")
                break;
            }
        }
    }
}
