# Convex-Hull
**Projeto:** Algoritmo para encontrar o Convex Hull de um conjunto de pontos

**Mateus Augusto Gomes**

O programa em C++ utiliza o algoritmo Graham Scan.

**Complexidade: O(n log n)** devido à ordenação dos pontos.

**Espaço Auxiliar:** **O(n)**, pois adicionalmente é usado uma pilha para armazenar os pontos.

**Aplicações:**

    - Processamento de Imagens: O convex hull pode traçar o contorno de objetos em imagens. 
    
    - Geometria Computacional: Pode ser usado para calcular o diâmetro de um conjunto de pontos.
    
    - Detecção de Colisões: Pode ser usado para determinar quando dois objetos então colidindo. 
      Usado em computação gráfica e simulações.



**Ambiente:** Notebook Acer i3 4gb RAM
          Linux Ubuntu


        
**Compilação:**

    g++ ConvexHull.cpp -o convexhull
    ./convexhull
    python3 plot.py
    
-> Compila o programa principal (C++) e faz o plot do resultado (Python)


**Bibliografia:**

    - Computer Science Handbook
    
    - site: GeeksForGeeks
    
    - Algoritmos: Teoria e Prática - Thomas H. Corman
