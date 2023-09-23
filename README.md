# Algoritmos de Rasterização

---

## Índice

* [Introdução](#Introdução)
* [Implementando o Algorítmo de Bresenham](#Implementando-o-Algorítmo-de-Bresenham)

---

### Introdução

#### Trabalho da disciplina **Introdução ao Processamento de Imagens** ministrada pelo professor **Maelson** da UNIPE

Para a compilação do projeto em MacOS, o programa requer as seguintes flags:

```bash
g++ main.cpp -o meu_programa -I. -framework OpenGL -framework GLUT
```

Para a compilação do projeto em Windows, é necessário o uso da seguinte linha de comando:

```bash
g++ main.cpp -o meu_programa -I"path/to/GLUT/include" -L"path/to/GLUT/lib" -lglut32 -lopengl32 -lglu32
```

> "`path/to/GLUT/include`" deve ser o caminho onde estão localizados os cabeçalhos (headers) do GLUT no Windows.  
> "`path/to/GLUT/lib`" deve ser o caminho onde estão localizadas as bibliotecas do GLUT.

Inicialmente, o projeto continha um arquivo Makefile, mas este foi removido para evitar problemas ao construir o projeto usando uma IDE e também ao tentar compilar em sistemas Windows e MacOS através da linha de comando.

---

### Implementação dos Pixels

Para a implementação de um algoritmo capaz de modificar os pixels na memória da aplicação, a documentação presente nos slides do professor foi crucial para entender os conceitos e facilitar a implementação. A maior dificuldade encontrada foi compreender como funcionavam as dimensões da aplicação para poder modificar os pixels desejados.

Ao modificar os 4 bytes por pixel, chegamos ao seguinte algoritmo para a edição de um pixel específico:

```c++
void PutPixel(int x, int y, int r, int g, int b) {
    if (x < 0 || x >= IMAGE_WIDTH || y < 0 || y >= IMAGE_HEIGHT) {
        return;
    }

    int index = (x + y * IMAGE_WIDTH) * 4;
    FBptr[index] = r;
    FBptr[index + 1] = g;
    FBptr[index + 2] = b;
    FBptr[index + 3] = 255;
}
```

Após a criação dessa função, a tarefa de modificar os pixels de acordo com as dimensões da imagem tornou-se mais fácil. Isso ocorreu porque foi possível entender que basta modificar os 4 bytes correspondentes ao pixel para editá-lo na posição desejada.

O resultado observado foi:

<p align="center">
    <br>
    <img src="./imagens/putpixel.png"/ width=512px height=512px>
    <h5 align="center">Figura 1 - Função putPixel()</h5>
    <br>
</p>

### Implementando o Algorítmo de Bresenham
