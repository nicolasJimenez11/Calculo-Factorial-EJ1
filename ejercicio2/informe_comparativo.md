Analisis Comparativo del Desempeño: Gestión de Estudiantes

INTRODUCCION Este informe compara el desempeño de un sistema de gestión de estudiantes antes y después de aplicar optimizaciones de memoria. Se evaluaron dos versiones del código: una sin optimización, utilizando estructuras estáticas y otra con optimización, usando memoria dinámica, bitfields y arrays ajustados.

METRICAS Las métricas evaluadas incluyen:

Memoria utilizada total Fragmentación detectada Tiempo de ejecución Resultados

MEMORIA UTILIZADA

Sin Optimización: 10400 bytes para 100 estudiantes (uso de estructuras fijas).
Con Optimización: 502 bytes por estudiante (uso de memoria dinámica y bitfields).
FRAGMENTACION

Sin Optimización: Alta. La memoria no se ajusta a las necesidades reales de los estudiantes.
Con Optimización: Baja o Nula. La memoria se ajusta dinámicamente, eliminando desperdicios.
TIEMPO DE EJECUCION

Sin Optimización: 0.000001 segundos para agregar un estudiante.
Con Optimización: 0.000002 segundos para agregar un estudiante (ligera diferencia en operaciones individuales, pero mejora en escalabilidad).
INFORME COMPARATIVO DE RESULTADOS Memoria Utilizada Total: ----Sin optimización: 10400 bytes para 100 estudiantes, debido al uso de estructuras fijas. ----Con optimización: 502 bytes por estudiante, gracias al uso de memoria dinámica.

Fragmentación Detectada: ----Sin optimización: Alta fragmentación debido al uso de estructuras estáticas. ----Con optimización: Baja o nula fragmentación, ya que se ajusta dinámicamente la memoria.

Tiempo de Ejecución: ----Sin optimización: 0.000001 segundos por estudiante. ----Con optimización: 0.000002 segundos por estudiante, con ligera diferencia pero mejor escalabilidad.

CONCLUSIONES -Las optimizaciones de memoria redujeron considerablemente el uso de memoria, eliminando la fragmentación y mejorando la eficiencia. Aunque el tiempo de ejecución puede ser ligeramente mayor con la optimización, el sistema es más escalable y eficiente para manejar grandes volúmenes de estudiantes.
