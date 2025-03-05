Projeto de Monitoramento com Sensores e Arduino

Descrição

Este projeto foi desenvolvido utilizando dois sensores: um sensor de luminosidade e um sensor de movimento. Ambos os sensores foram conectados a um Arduino, que realiza a leitura dos dados e os armazena em um banco de dados Firebase. Os dados são automaticamente atualizados em uma grid HTML sempre que ocorre uma mudança no estado dos sensores.

Tecnologias Utilizadas

Arduino: Para a leitura dos sensores.

Sensores:

Sensor de Luminosidade (LDR)

Sensor de Movimento (PIR)

Firebase: Para armazenamento dos dados coletados.

HTML, CSS e JavaScript: Para exibição dos dados em tempo real em uma grid.

Funcionalidades

Captura automática de dados dos sensores.

Envio das leituras para o Firebase.

Atualização dinâmica dos dados em uma interface web.

Como Executar o Projeto

Montagem do Circuito:

Conecte os sensores ao Arduino conforme o esquema de ligação apropriado.

Configuração do Firebase:

Configure um banco de dados Firebase e obtenha as credenciais necessárias.

Upload do Código para o Arduino:

Utilize a IDE do Arduino para carregar o código que realiza a leitura dos sensores e envia os dados ao Firebase.

Execução da Interface Web:

Abra o arquivo HTML no navegador para visualizar a grid com os dados em tempo real.

Requisitos

Placa Arduino (ex: Arduino Uno)

Sensor de Luminosidade (LDR)

Sensor de Movimento (PIR)

Módulo Wi-Fi (caso o Arduino não tenha conectividade)

Conta e configuração no Firebase

Ambiente de desenvolvimento (IDE do Arduino)
