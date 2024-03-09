<h1>Keylogger em C++</h1><br>
Um keylogger é um programa de software ou dispositivo de hardware que registra as teclas digitadas em um computador, normalmente de forma oculta. Embora os keyloggers tenham várias aplicações legítimas, como monitoramento parental e análise de desempenho de usuários, eles também podem ser usados para atividades maliciosas, como roubo de informações confidenciais. Este repositório fornece uma visão geral de uma implementação simples de keylogger em C++. <br><br>

<h1>Introdução</h1>
A implementação apresentada é um keylogger simples em C++, por ser uma linguagem de baixo nível. O código registra as teclas digitadas pelo usuário e as salva em um arquivo de log. O programa utiliza a biblioteca Windows.h para interagir com o sistema operacional Windows e capturar as teclas pressionadas. <br><br>

<h1>Funcionamento</h1><br>
<b>Captura de Teclas</b>:  O programa utiliza a função GetAsyncKeyState da biblioteca Windows.h para verificar o estado de cada tecla do teclado. Esta função retorna um valor que indica se uma determinada tecla está sendo pressionada. O loop principal do programa itera por todas as teclas possíveis (de 8 a 255) e verifica se cada tecla está sendo pressionada. Se uma tecla é detectada como pressionada, seu código é registrado no arquivo de log.<br>

<b>Escrita no Arquivo de Log</b>: O arquivo de log é aberto em modo de escrita, leitura e atualização utilizando a função open da classe ofstream da biblioteca fstream. A cada tecla pressionada, o código da tecla é escrito no arquivo de log. Além disso, algumas teclas especiais, como SHIFT, ESCAPE e ENTER, são tratadas de forma diferente para facilitar a interpretação do arquivo de log. <br>

<b>Ocultação do Console</b>: Para tornar o keylogger mais discreto, a janela do console é escondida utilizando a função FindWindowA para encontrar a janela do console e ShowWindow para ocultá-la.<br>

<b>Limitações e Considerações de Segurança</b>: É importante ressaltar que este keylogger é apenas um exemplo educacional e não deve ser usado para fins maliciosos. Além disso, este keylogger possui algumas limitações e considerações de segurança:<br>

<ul>Este keylogger só funciona em sistemas operacionais Windows devido ao uso da biblioteca Windows.h.<br>
O programa deve ser executado com privilégios de administrador para funcionar corretamente.<br>
O keylogger pode ser detectado por software antivírus como uma ameaça de segurança.</ul><br>
