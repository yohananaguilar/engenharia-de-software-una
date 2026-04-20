# Atividade Prática ESP32 com FreeRTOS

Atividade prática da UC Organização de Computadores, no 4º semestre, com foco em multitarefa, concorrência e controle por eventos no ESP32 usando FreeRTOS.

## Conteudo do projeto

- [docs/enunciado/atividade-pratica-esp32-freertos-enunciado.pdf](docs/enunciado/atividade-pratica-esp32-freertos-enunciado.pdf)
  - PDF com o enunciado original.
- [docs/entrega/](docs/entrega/)
  - Pasta reservada para o PDF de entrega final, quando houver.
- [exercicios/exercicio1/sketch.ino](exercicios/exercicio1/sketch.ino)
- [exercicios/exercicio1/diagram.json](exercicios/exercicio1/diagram.json)
- [exercicios/exercicio2/sketch.ino](exercicios/exercicio2/sketch.ino)
- [exercicios/exercicio2/diagram.json](exercicios/exercicio2/diagram.json)
- [exercicios/exercicio3/sketch.ino](exercicios/exercicio3/sketch.ino)
- [exercicios/exercicio3/diagram.json](exercicios/exercicio3/diagram.json)
- [exercicios/exercicio4/sketch.ino](exercicios/exercicio4/sketch.ino)
- [exercicios/exercicio4/diagram.json](exercicios/exercicio4/diagram.json)

Cada pasta dentro de exercicios representa um projeto Wokwi independente.

## Resumo dos exercicios

- Exercicio 1
  - adiciona o LED4 e cria a taskLED4 no core 1, com 1 segundo ligado e 1 segundo desligado.
- Exercicio 2
  - adiciona o BOTAO2, a variavel global ligarLED4 e faz o LED4 piscar 3 vezes rapidamente quando o botao 2 e pressionado.
- Exercicio 3
  - adiciona um segundo botao para fazer o LED3 piscar em alta velocidade, mantendo o comportamento do botao original.
- Exercicio 4
  - adiciona um terceiro botao que desliga completamente o LED3 ate que outro botao seja pressionado.

## Tecnologias e simulacao

- ESP32
- Arduino framework
- FreeRTOS
- Wokwi

## Como executar

1. Acesse https://wokwi.com/ e crie um novo projeto ESP32.
2. Escolha a pasta do exercicio que deseja testar.
3. Copie o conteudo de sketch.ino e diagram.json para o projeto do Wokwi.
4. Inicie a simulacao.
5. Use as teclas Q, W e E para acionar os botoes, quando o exercicio tiver esses controles.

## Pinagem usada

- LED1: GPIO 2
- LED2: GPIO 4
- LED3: GPIO 5
- LED4: GPIO 18
- BOTAO1 ou BOTAO: GPIO 15
- BOTAO2: GPIO 16
- BOTAO3: GPIO 17

## Observacao

Os botoes usam INPUT_PULLUP, entao o acionamento ocorre em nivel LOW. Se a montagem mudar, ajuste apenas os defines no sketch correspondente.