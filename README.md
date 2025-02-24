# Código de Função Autodestrutiva em C

Este projeto contém um programa em C que implementa uma função **autodestrutiva**. Após a execução da função `funcao_autodestrutiva()`, o próprio código-fonte (`autodead.c`) é modificado para remover essa função, tornando-a irreversível sem restauração do arquivo original.

## ⚠️ Aviso Importante

Este código é **experimental e destrutivo**. Use-o apenas em ambientes controlados e faça backup do arquivo antes da execução. **A função se auto-remove do código-fonte após a execução.**

## 📂 Estrutura do Código

- `funcao_autodestrutiva()`:  
  - Localiza sua própria definição no código-fonte.  
  - Remove seu próprio bloco de código (`void funcao_autodestrutiva() { ... }`).  
  - Reescreve o arquivo sem essa função.

- `main()`:  
  - Apenas chama `funcao_autodestrutiva()`.

## 🚀 Como Usar

1. **Crie o arquivo-fonte**  
   Salve o código como `autodead.c`.

2. **Compile o código**  
   ```sh
   gcc autodead.c -o autodead
