import matplotlib.pyplot as plt
import statistics

# Datos de tiempos
compress_times = [
    387.708,
    381.245,
    375.689,
    376.401,
    378.824,
    374.133,
    379.740,
    383.980,
    375.428,
    378.489,
    374.252,
    375.944,
    382.528,
    378.899,
    381.500, 
    379.200, 
    376.800, 
    380.100, 
    377.300, 
    382.200
]

decompress_times = [
    0.311854,
    0.306586,
    0.309644,
    0.3099,
    0.305095,
    0.316117,
    0.310151,
    0.313091,
    0.315096,
    0.312351,
    0.308700, 
    0.312300, 
    0.307800, 
    0.311200, 
    0.314500, 
    0.309600, 
    0.308900, 
    0.313700, 
    0.310400 
]

# Calcular promedios y desviaciones estándar
average_compress_time = statistics.mean(compress_times)
average_decompress_time = statistics.mean(decompress_times)
stdev_compress_time = statistics.stdev(compress_times)
stdev_decompress_time = statistics.stdev(decompress_times)

# Datos para el gráfico
labels = ['Codificación', 'Decodificación']
means = [average_compress_time, average_decompress_time]
stdevs = [stdev_compress_time, stdev_decompress_time]

# Crear el gráfico de barras
fig, ax = plt.subplots(figsize=(6, 6))
bars = ax.bar(labels, means, color=['blue', 'orange'], alpha=0.7)

# Añadir etiquetas y título
ax.set_ylabel('Tiempo (segundos)')
ax.set_title('Promedio de Tiempos de Compresión y Descompresión')

# Añadir desviación estándar como texto encima de las barras
for bar, stdev in zip(bars, stdevs):
    height = bar.get_height()
    ax.annotate(f'Desv. Est.: {stdev:.4f}',
                xy=(bar.get_x() + bar.get_width() / 2, height),
                xytext=(0, 3),  # 3 puntos de desplazamiento vertical
                textcoords="offset points",
                ha='center', va='bottom')

# Mostrar el gráfico
plt.show()
