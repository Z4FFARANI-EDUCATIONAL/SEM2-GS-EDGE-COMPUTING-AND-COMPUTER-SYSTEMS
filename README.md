![banner](./assets/banner.png)

![simulator](./assets/simulator.png)

# INTEGRANTES
- **Guilherme Santos Nunes** | 558989
- **Kaique Rodrigues Zaffarani** | 556677

## LINKS
- **[VÍDEO EXPLICATIVO]()**
- **[SIMULADOR](https://wokwi.com/projects/414372914280213505)**

<br>

# PROJETO
Este projeto apresenta um plano de Certificação sustentável desenvolvido pela fictícia empresa Econy. A solução integra tecnologias de IoT (Internet das Coisas) e Serviços em nuvem para monitorar e validar emissões de CO2 de clientes, incentivando práticas empresariais sustentáveis.

O Simulador utiliza um potenciômetro para medir dados relacionados às emissões de CO2 (dióxido de carbono), exibindo-os em um display LCD. Esses dados são enviados para um Serviço em nuvem por meio de uma conexão Wi-Fi, utilizando o protocolo MQTT. O Serviço em nuvem processa e encaminha os dados para um Cliente MQTT, facilitando Auditoria realizada por terceiros.

O plano é dividido em cinco etapas:

- **Simulador** | Conecta um potenciômetro e um display LCD a um microcontrolador, que transmite os dados captados para o Serviço em nuvem por meio do protocolo MQTT.

- **Serviço em nuvem** | Máquina virtual configurada para receber, processar e encaminhar os dados do Simulador para o Cliente MQTT.

- **Cliente MQTT** | Aplicativo que publica e inscreve em tópicos MQTT predefinidos, permitindo que os dados enviados pelo Simulador sejam visualizados em tempo real.

- **Auditoria** | Empresa terceirizada que valida os dados coletados, aplicando protocolos rigorosos aprovados por normas nacionais ou internacionais.

- **Certificação** | Emissão de um certificado que comprova o compromisso sustentável da empresa, gerando maior credibilidade no mercado em que atua.

<br>

# INSTRUÇÕES
1. Em um terminal, clonar o repositório:
```bash
git clone https://github.com/Z4FFARANI-EDUCATIONAL/SEM2-GS-EDGE-COMPUTING-AND-COMPUTER-SYSTEMS.git
```

2. No terminal, navegar até a pasta do projeto:
```bash
cd SEM2-GS-EDGE-COMPUTING-AND-COMPUTER-SYSTEMS
```

3. O projeto [IoThunder](https://github.com/Z4ffarani/IoThunder) informa o passo a passo necessário para configurar um Serviço em nuvem na AWS (Amazon Web Services).

4. Para rodar o Simulador, seguir o link disponibilizado e clicar no botão de iniciar. Levará algum tempo até que o Simulador se conecte à rede pública do Wokwi e ao Serviço em nuvem. É possível regular o potenciômetro para registrar valores que serão exibidos no display LCD e o Cliente MQTT. Para utilização do Simulador físico, é necessário executar o código presente no arquivo `simulator.ino` na pasta `docs`, assim como instalar as bibliotecas dos sensores presentes na pasta `libraries`. O programa [Arduino IDE](https://www.arduino.cc/en/software) é adequado para o teste.

5. A Auditoria deve instalar o [Cliente MQTT](https://mymqtt.app/en). No aplicativo, os dados serão dispostos a partir da inscrição no tópico MQTT `/iot/co2`.

<br>

# FUNÇÕES
`docs/simulator.ino`:
- **Inclusão de bibliotecas** | Importa as bibliotecas necessárias para a operação do microcontrolador e a comunicação com o sensor/atuador, permitindo o uso de funções específicas.
  
- **Constantes de endereços e credenciais** | Recebe valores que permitem a comunicação com o Serviço em nuvem, como rede Wi-Fi e informações específicas.

- **Definição de portas de entrada** | Estabelece as portas digitais e analógicas do microcontrolador que serão usadas para conectar e ler os dados do sensor/atuador, garantindo a correta configuração do hardware.
  
- **Funções de inicialização** | Inicia o módulo Wi-Fi do microcontrolador, o Serviço em nuvem e o atuador (display LCD).

- **Funções de verificação em loop** | Verifica a conexão do Serviço em nuvem e exibe mensagens de status no monitor serial, além de publicar os dados captados pelo potenciômetro e exibir parte deles no display LCD do Simulador.

- **Leitura de sensor e atuador** | Configura e lê os dados do potenciômetro e do display LCD, processando os dados de CO2 em ppm (partes por milhão).

- **Envio de dados** | Funções reconhecem o nível do potenciômetro e o enviam para o Serviço em nuvem por meio do tópico MQTT `/iot/co2`, que por sua vez envia outros tipos de dados para o Cliente MQTT e para o display LCD.

<br>

# DIAGRAMA
![DIAGRAM](./assets/diagram.png)

<br>

# OBSERVAÇÕES
- O projeto é destinado a fins acadêmicos, sendo inteiramente prototipado e validado em ambiente controlado. A responsabilidade pela experimentação real é do cliente.

- A estabilidade da conexão Wi-Fi é fundamental para o funcionamento do sistema. Para o Simulador físico, é preciso confirmar que o microcontrolador está dentro do alcance da rede sem fio para garantir a transmissão confiável de dados.

- A instalação do Simulador no estabelecimento contemplado é realizada pela Econy, sendo hardware e software configurados corretamente.

- Além de ser terceirizado, o processo de Auditoria não é inspecionado pela Econy, que apenas fornece os dados captados pelo Simulador para a Auditoria durante a validação para Certificação.

- As manutenções periódicas do Simulador estão incluídas no plano.

- O Serviço em nuvem é desativado assim que a Auditoria concluir seu processo de validação no estabelecimento do cliente.

- Dependendo dos requisitos específicos de cada Certificação, diferentes tipos de validação podem ser requisitados pela Auditoria.

<br>

# TECNOLOGIAS
[![Arduino](https://img.shields.io/badge/-Arduino-00979D?style=for-the-badge&logo=Arduino&logoColor=white)](https://www.arduino.cc/en/software)
[![AWS](https://img.shields.io/badge/AWS-%23FF9900.svg?style=for-the-badge&logo=amazon-aws&logoColor=white)](https://aws.amazon.com)
[![Ubuntu](https://img.shields.io/badge/Ubuntu-E95420?style=for-the-badge&logo=ubuntu&logoColor=white)](https://ubuntu.com)

<br>

# REFERÊNCIAS
- **[Instalação de bibliotecas no Arduino IDE](https://docs.arduino.cc/software/ide-v1/tutorials/installing-libraries/)**
- **[Medições de dióxido de carbono](https://www.vaisala.com/sites/default/files/documents/CEN-TIA-Parameter-How-to-measure-CO2-Application-note-B211228PT-A.pdf)**