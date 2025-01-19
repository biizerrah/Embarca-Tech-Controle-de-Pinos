# Embarca Tech Controle de Pinos

## O objetivo dessa atividade é usar a porta serial UART para controlar pinos GPIO do microcontrolador RP2040.

### Requisitos obrigatórios para a execução dessa atividade:

- Ligar LED verde (GPIO 11) – desligar as demais GPIOs;
- Ligar LED azul (GPIO 12) - desligar as demais GPIOs;
- Ligar LED vermelho (GPIO 13) - desligar as demais GPIOs;
- Ligar os três LEDs (luz branca);
- Desligar todos os LEDs;
- Acionar o buzzer por 2 segundos – emissão de sinal sonoro

## Instalação de Pré-requisitos

Para configurar o ambiente de desenvolvimento, siga as instruções abaixo:

### 1. Instalar o Visual Studio Code
- Acesse o site oficial e faça o download: [Visual Studio Code](https://code.visualstudio.com/).
- Instale o programa e configure conforme necessário.

### 2. Instalar o CMake
- Baixe o instalador do CMake: [CMake](https://cmake.org/download/).
- Durante a instalação, marque a opção **"Add CMake to the system PATH"**.
- Conclua a instalação.

### 3. Instalar o GCC para ARM
- Baixe o compilador ARM GNU em: [GCC ARM Toolchain](https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm).
- Após a instalação, adicione o diretório do executável ao **PATH**:
  - Vá para **Configurações do Sistema > Variáveis de Ambiente**.
  - Edite a variável `Path` e adicione:
    ```
    C:\Program Files (x86)\Arm GNU Toolchain\<versão>\bin
    ```
  - Substitua `<versão>` pela versão instalada.

### 4. Instalar o Git
- Faça o download: [Git para Windows](https://git-scm.com/).
- Instale o programa e configure-o.
- Abra o terminal (Git Bash ou CMD) e configure seu nome e e-mail:
  ```bash
  git config --global user.name "Seu Nome"
  git config --global user.email "seu.email@exemplo.com"

### 5. Uma placa educacional BitDogLab
 - Cabo tipo micro-usb para usb-a 
 - Download do software de emulação de terminal [PuTTY](https://www.putty.org/?paipat) para estabeler a correta conexão entre o computador e o microcontrolador.