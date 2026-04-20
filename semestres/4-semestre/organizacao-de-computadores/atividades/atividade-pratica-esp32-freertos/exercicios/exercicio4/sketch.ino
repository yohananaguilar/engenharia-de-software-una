#include <Arduino.h>

#define LED1 2
#define LED2 4
#define LED3 5

#define BOTAO1 15
#define BOTAO2 16
#define BOTAO3 17

enum ComandoLED3 {
  LED3_PISCAR_500MS,
  LED3_PISCAR_100MS,
  LED3_DESLIGAR
};

QueueHandle_t filaLED3;

void aguardarSoltarBotao(uint8_t pino) {
  while (digitalRead(pino) == LOW) {
    vTaskDelay(20 / portTICK_PERIOD_MS);
  }
}

void taskLED1(void *pvParameters) {
  while (true) {
    digitalWrite(LED1, !digitalRead(LED1));
    vTaskDelay(300 / portTICK_PERIOD_MS);
  }
}

void taskLED2(void *pvParameters) {
  while (true) {
    digitalWrite(LED2, !digitalRead(LED2));
    vTaskDelay(700 / portTICK_PERIOD_MS);
  }
}

void taskBotao1(void *pvParameters) {
  ComandoLED3 comando = LED3_PISCAR_500MS;

  while (true) {
    if (digitalRead(BOTAO1) == LOW) {
      Serial.println("Botao 1 pressionado - LED3 em 500 ms");
      xQueueSend(filaLED3, &comando, portMAX_DELAY);
      aguardarSoltarBotao(BOTAO1);
      vTaskDelay(80 / portTICK_PERIOD_MS);
    }
    vTaskDelay(20 / portTICK_PERIOD_MS);
  }
}

void taskBotao2(void *pvParameters) {
  ComandoLED3 comando = LED3_PISCAR_100MS;

  while (true) {
    if (digitalRead(BOTAO2) == LOW) {
      Serial.println("Botao 2 pressionado - LED3 em 100 ms");
      xQueueSend(filaLED3, &comando, portMAX_DELAY);
      aguardarSoltarBotao(BOTAO2);
      vTaskDelay(80 / portTICK_PERIOD_MS);
    }
    vTaskDelay(20 / portTICK_PERIOD_MS);
  }
}

void taskBotao3(void *pvParameters) {
  ComandoLED3 comando = LED3_DESLIGAR;

  while (true) {
    if (digitalRead(BOTAO3) == LOW) {
      Serial.println("Botao 3 pressionado - LED3 desligado");
      xQueueSend(filaLED3, &comando, portMAX_DELAY);
      aguardarSoltarBotao(BOTAO3);
      vTaskDelay(80 / portTICK_PERIOD_MS);
    }
    vTaskDelay(20 / portTICK_PERIOD_MS);
  }
}

void taskLED3(void *pvParameters) {
  bool bloqueado = false;
  ComandoLED3 comandoRecebido;

  while (true) {
    if (xQueueReceive(filaLED3, &comandoRecebido, portMAX_DELAY) == pdTRUE) {
      switch (comandoRecebido) {
        case LED3_DESLIGAR:
          bloqueado = true;
          digitalWrite(LED3, LOW);
          break;

        case LED3_PISCAR_500MS:
          bloqueado = false;
          digitalWrite(LED3, HIGH);
          vTaskDelay(500 / portTICK_PERIOD_MS);
          digitalWrite(LED3, LOW);
          break;

        case LED3_PISCAR_100MS:
          bloqueado = false;
          digitalWrite(LED3, HIGH);
          vTaskDelay(100 / portTICK_PERIOD_MS);
          digitalWrite(LED3, LOW);
          break;
      }

      if (bloqueado) {
        digitalWrite(LED3, LOW);
      }
    }
  }
}

void setup() {
  Serial.begin(115200);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);

  pinMode(BOTAO1, INPUT_PULLUP);
  pinMode(BOTAO2, INPUT_PULLUP);
  pinMode(BOTAO3, INPUT_PULLUP);

  filaLED3 = xQueueCreate(10, sizeof(ComandoLED3));

  xTaskCreatePinnedToCore(taskLED1, "LED1", 2048, NULL, 1, NULL, 0);
  xTaskCreatePinnedToCore(taskLED2, "LED2", 2048, NULL, 1, NULL, 0);
  xTaskCreatePinnedToCore(taskBotao1, "BOTAO1", 2048, NULL, 2, NULL, 0);
  xTaskCreatePinnedToCore(taskBotao2, "BOTAO2", 2048, NULL, 2, NULL, 0);
  xTaskCreatePinnedToCore(taskBotao3, "BOTAO3", 2048, NULL, 2, NULL, 0);

  xTaskCreatePinnedToCore(taskLED3, "LED3", 2048, NULL, 1, NULL, 1);
}

void loop() {
}