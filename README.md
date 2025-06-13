
# Tarefa: Roteiro de FreeRTOS #1 - EmbarcaTech 2025

Autor: **Miguel Carvalho de Mederos**

Curso: Residência Tecnológica em Sistemas Embarcados

Instituição: EmbarcaTech - HBr

Brasília, 13 de Junho de 2025

---
## Descrição

Este projeto implementa um sistema multitarefa usando FreeRTOS para controlar periféricos da placa BitDogLab com Raspberry Pi Pico. O sistema gerencia concorrentemente um LED RGB, um buzzer e dois botões com controle de suspensão e retomada de tarefas.

## Funcionalidades Principais
- **Tarefa de LED RGB**: Alterna ciclicamente entre vermelho, verde e azul a cada 500ms
- **Tarefa de Buzzer**: Emite bipes curtos periódicos a cada 1 segundo
- **Controle por Botões**:
  - Botão A: Suspende/retoma a tarefa do LED
  - Botão B: Suspende/retoma a tarefa do buzzer

## Estrutura do Projeto
```
meu_projeto_freertos/
├── CMakeLists.txt
├── pico_sdk_import.cmake
├── FreeRTOS/            (clone do kernel FreeRTOS)
├── src/
│   ├── buttons.c
│   ├── buzzer.c
│   └── leds.c
├── include/
│   ├── FreeRTOSConfig.h
│   ├── buttons.h
│   ├── buzzer.h
│   └── leds.h
└── main.c
```

## Dependências
- [FreeRTOS-Kernel](https://github.com/FreeRTOS/FreeRTOS-Kernel)
- pico-sdk (já configurado no ambiente)

## Compilação e Instalação
1. Clone o repositório:
```bash
git clone https://github.com/EmbarcaTech-2025/tarefa-freertos-1-Miguel-MCM
cd tarefa-freertos-1-Miguel-MCM
```

2. Configure o ambiente de compilação:
```bash
mkdir build
cd build
cmake ..
```

3. Compile o projeto:
```bash
make -j4
```

4. Instale na placa:
- Pressione o botão BOOTSEL na BitDogLab
- Conecte via USB
- Copie o arquivo `embarcatech-freertos-tarefa-1.uf2` para a unidade de armazenamento

## Respostas às Questões de Reflexão

### 1. O que acontece se todas as tarefas tiverem a mesma prioridade?
Quando todas as tarefas têm a mesma prioridade, o escalonador do FreeRTOS utiliza um algoritmo Round Robin. Cada tarefa executa por um quantum de tempo (definido por `configTICK_RATE_HZ`) e depois cede voluntariamente a CPU. Neste projeto, como todas as tarefas usam `vTaskDelay`, elas cooperam naturalmente, permitindo que todas executem sem bloquear indefinidamente.

### 2. Qual tarefa consome mais tempo da CPU?
A tarefa de botões consome mais tempo da CPU porque:
- Faz polling constante dos botões a cada 100ms
- Não bloqueia por longos períodos como as outras tarefas
- Executa verificações de estado e debounce continuamente

### 3. Quais seriam os riscos de usar polling sem prioridades?
- **Responsividade**: Tarefas críticas podem ter atrasos no processamento
- **Starvation**: Tarefas de baixa prioridade podem nunca executar
- **Eficiência energética**: CPU fica constantemente ativa mesmo sem trabalho útil
- **Determinismo**: Comportamento do sistema torna-se menos previsível

---

## 📜 Licença
GNU GPL-3.0.
