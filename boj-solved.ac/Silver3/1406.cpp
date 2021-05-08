import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() = with(BufferedReader(InputStreamReader(System.`in`))){
    var s = readLine()
    val lst = Stack<Char>()
    var rst = Stack<Char>()
    for(a in s) lst.push(a)
    for(i in 1..readLine().toInt()) {
        var ip = readLine().split(' ')
        when (ip[0]) {
            "L" -> if(!lst.empty()) rst.push(lst.pop())
            "D" -> if(!rst.empty()) lst.push(rst.pop())
            "B" -> if(!lst.empty()) lst.pop()
            else -> {
                lst.push(ip[1][0])
            }
        }
    }
    println(lst.toCharArray()+rst.toCharArray().reversed())
}

// /
// import java.io.BufferedReader
// import java.io.InputStreamReader
// import java.lang.StringBuilder
// import java.util.*

// fun main() = with(BufferedReader(InputStreamReader(System.`in`))){
//     var s = readLine()
//     var list = LinkedList<Char>()
//     for(a in s) list.add(a)
//     var it = list.listIterator()
//     while(it.hasNext()) it.next()
//     var n = readLine().toInt()
//     for(i in 1..n) {
//         var ip = readLine().split(' ')
//         when (ip[0]) {
//             "L" -> if (it.hasPrevious()) it.previous()
//             "D" -> if (it.hasNext()) it.next()
//             "B" -> {
//                 if (it.hasPrevious()) {
//                     it.previous()
//                     it.remove()
//                 }
//             }
//             else -> it.add(ip[1][0])
//         }
//     }
//     println(list.toCharArray())
// }