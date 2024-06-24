import matplotlib.pyplot as plt
import statistics

# Datos de tiempos
encode_times = [
    2.47918,
    2.46652,
    2.44112,
    2.46576,
    2.42567,
    2.45809,
    2.47595,
    2.43934,
    2.45303,
    2.3799,
    2.40524,
    2.36987,
    2.38006,
    2.40001,
    2.44393,
    2.38991,
    2.41997,
    2.39017,
    2.38678,
    2.39971
]
decode_times = [
    1.68173,
    1.65619,
    1.65144,
    1.66109,
    1.67242,
    1.65174,
    1.66621,
    1.66055,
    1.60525,
    1.62482,
    1.6098,
    1.6101,
    1.69012,
    1.64489,
    1.62116,
    1.60985,
    1.62015,
    1.61323,
    1.61992,
    1.61025
]

# Calcular promedios y desviaciones estándar
average_encode_time = statistics.mean(encode_times)
average_decode_time = statistics.mean(decode_times)
stdev_encode_time = statistics.stdev(encode_times)
stdev_decode_time = statistics.stdev(decode_times)

# Datos para el gráfico
labels = ['Codificación', 'Decodificación']
means = [average_encode_time, average_decode_time]
stdevs = [stdev_encode_time, stdev_decode_time]

# Crear el gráfico de barras
fig, ax = plt.subplots(figsize=(6, 6))
bars = ax.bar(labels, means, color=['blue', 'orange'], alpha=0.7)

# Añadir etiquetas y título
ax.set_ylabel('Tiempo (segundos)')
ax.set_title('Promedio de Tiempos de Codificación y Decodificación')

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
