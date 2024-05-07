open System.IO
open System

let path = "./"
let out = "combine.csv"

let files = Directory.GetFiles(path, "*.csv")
let data = [ for fName in files do yield File.ReadAllLines fName |> Array.toList ]

seq {
    for i in 0..data[0].Length-1 do
        seq {
            for d in data do
                yield d[i]
        }
        |> fun x -> String.Join(",", x)
}
|> Seq.toList
|> fun x -> File.WriteAllLines(out, x)