import Data.List (sortBy)
import Data.Ord (comparing)

-- Lista de estudiantes (nombre, calificación)
students :: [(String, Int)]
students = [
    ("Ana", 85),
    ("Pedro", 90),
    ("Luis", 85),
    ("Maria", 95),
    ("Jose", 90),
    ("Lucia", 85)
    ]

-- Función para ordenar los estudiantes
sortStudents :: [(String, Int)] -> [(String, Int)]
sortStudents = sortBy (comparing (negate . snd) <> comparing fst)

-- Imprimir la lista ordenada
main :: IO ()
main = print (sortStudents students)
