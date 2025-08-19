Repositório do **Trabalho 1** da disciplina de **Linguagens Formais e Autômatos** — Curso de Ciência da Computação, campus Foz do Iguaçu.


## 📝 Descrição

Este projeto consiste na implementação de um **simulador de Autômato Finito Determinístico (AFD)**, conforme as especificações fornecidas pelo professor. O simulador é executado via prompt do sistema (sem interface gráfica)
e processa cadeias de entrada com base em uma definição de autômato lida de um arquivo `.txt`.

---

## ⚙️ Funcionalidades

- Leitura da definição do AFD a partir de um arquivo texto.
- Interação com o usuário via terminal para entrada de cadeias.
- Suporte ao símbolo especial `@` para representar a cadeia vazia.
- Impressão do passo a passo do processamento da cadeia.
- Indicação se a cadeia foi **aceita** ou **rejeitada**.

---

## 🧾 Formato do Arquivo de Entrada

O arquivo que define o AFD deve conter:

1. Alfabeto:  
alfabeto={a,b,c,0,1,2}

markdown
Copy
Edit

2. Conjunto de estados (o estado inicial deve ser `q0`):  
estados={q0,q1,q2,q3,q4,q5}

markdown
Copy
Edit

3. Estados finais:  
finais={q2,q5}

markdown
Copy
Edit

4. Transições, uma por linha no formato `(estado,simbolo)=estado_destino`:  
(q0,a)=q1
(q1,a)=q2
(q1,b)=q1
...

yaml
Copy
Edit

---

## 💻 Execução

### Compilação
bash
gcc afd_simulador.c -o afd_simulador
./afd_simulador

Uso
O programa solicitará o caminho do arquivo com a definição do AFD e, em seguida, aceitará entradas de cadeias para simulação.

Exemplo de saída:

css
Copy
Edit
[q0]ab00cb
[q1]b00cb
[q1]00cb
[q4]0cb
[q2]cb
[q3]b
[q2]
ACEITA
