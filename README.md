# Hexdump

Pequeño programa de línea de comandos escrito en C que lee datos desde la entrada estándar y los muestra en formato hexadecimal.

## Compilar

Con GCC:

```bash
gcc -Wall -Wextra -o hexdump main.c
```

Si el proyecto tiene varios archivos `.c`:

```bash
gcc -Wall -Wextra -o hexdump src/*.c
```

## Uso

Pasa el contenido al programa mediante una tubería:

```bash
cat archivo | ./hexdump
```

También puedes introducir texto directamente:

```bash
echo "Hola, mundo" | ./hexdump
```

## Ejemplo de salida

```text
00000000  48 6f 6c 61 2c 20 6d 75   6e 64 6f 0a               [ H o l a , . m u n d o . ]
```
