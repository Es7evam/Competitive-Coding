# Geometria

## Operações


## Dot Product - Produto Escalar (.)
É definido como o módulo da projeção de um vetor em outro.
Toma dois vetores e devolve um escalar como resultado.

Por exemplo, tomando os vetores
```
v1 = {x1, y1} e v2 = {x2, y2}
```
Temos:
```
v1.v2 = x1*x2 + y1+y2
```

Um produto escalar entre os vetores p e q pode ser definido como:
```
p . q = |p|*|q|*cos(angulo)
```

Perceba que, como é utilizado o cosseno, não fará diferença a orientação escolhida para o cálculo dele: `(p.q = q.p)`. <br>
Analisando o cosseno, sabemos que:
- Se p.q > 0, então o angulo é menor que 90 graus.
- Se p.q < 0, então o angulo é maior que 90 graus
- Se p.q = 0, então o angulo é igual a 90 graus.

Valem as propriedades (facilmente demonstráveis) <br>
- `a.(b+c) = a.b + a.c`
- `a.a = |a|²`

## Cross Product - Produto Vetorial (X)
É definido como o vetor perpenticular ao produto de ambos os quais o produto é feito, sendo o seu tamanho igual à área que o paralelogramo entre os vetores é formado. <br> ![crossproduct.png](./class/crossproduct.png) <br>

Pode ser representado pela determinante da matriz cujos coeficientes são os vetores, por exemplo, v1 = {x1, y1} e v2 = {x2, y2}:

<center>

|x1 y1| <br>
|x2 y2|

</center>

Que é:
```
v1 X v2 = x1*y2 - y1*x2
```
Outro modo de denotar o produto vetorial é:
```
v1 X v2 = |v1|*|v2|*sen(angulo v1->v2)
```

Perceba que agora o ângulo faz diferença, já que este vai alterar o sentido do vetor do resultado. <br>
Analisando pelo seno, sabemos então, já que os módulos são sempre positivos, que o produto vetorial entre dois vetores p e q será:
- Se p X q > 0, então o angulo é menor que 0 graus.
- Se p X q < 0, então o angulo é maior que 0 graus.
- Se p X q = 0, então o angulo é igual a 0 graus, logo os vetores são paralelos.

O que pode ser usado, por exemplo, para saber a orientação entre dois vetores, para saber se um poligono é convexo. <br>

### Cálculo de Área de um Poligono Convexo
Perceba que, à partir de qualquer ponto de um polígono convexo, de acordo com a sua própria definição, é possível traçar uma reta até qualquer um de seus outros vértices, formando triangulos, como na figura abaixo.
![convexpolygon.png](./class/convexpolygon.png)

Como o produto vetorial entre dois vetores, em módulo, retorna a área do paralelogramo que seria formado por eles, isso significa que o produto vetorial dividido por 2 é a área do triângulo que divide o paralelogramo ao meio. <br>
Voltando à figura acima, podemos, por exemplo, calcular a área do triângulo formado pelos vetores AB, BC e AC, tomando o produto vetorial AB X BC / 2.
Assim, fazendo sucessivamente o mesmo com os triângulos de 1 a 8, somando as áreas temos a área total do polígono.

## Pontos e Retas

### Distância entre dois pontos
É dada pelo módulo da subtração entre os próprios pontos <br>
```
dist(p, q) = |p-q|
```

### Distância entre ponto e segmento de reta
Primeiramente é necessário checar se o dot product entre os vetores que representam o triângulo formado pelas extremidades da reta são maiores do que 0, já que se não for significa que o ponto da reta mais próximo ao ponto é uma das suas extremidades.
Caso isso ocorra, basta calcular a altura do triângulo formado, então, a distância será dada por: <br>

```c
if((r-a).(b-a) >= 0 && (r-b).(a-b) >= 0){
    return abs((b-a)x(r-a)/len(a-b));
}else{
    return min(len(r-a), len(r-b));
}   
```

### Representação de retas
Uma reta pode ser representada como um ponto, que indica o "ponto de partida" e um vetor diretor, que indica o "sentido" dela. <br>

Para checar se um ponto pertence a uma reta, basta utilizar o produto vetorial entre o vetor formado pelo "ponto inicial" e o ponto desejado e o vetor diretor da reta. Caso o resultado seja 0 significa que o seno entre esses vetores é 0 e portanto o ângulo entre eles é igual a 0 ou 180 graus, assim sendo considerados como linear.

### Intersecção de Retas
Tomando o sistema linear dado por:
```
a1x + b1y = c1
a2x + b2y = c2
```

Utilizando a regra de Cramer (tome cuidado com determinantes iguais a 0) com as matrizes da imagem abaixo.

![cramer.png](./class/cramer.png)
