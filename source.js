var firebaseConfig = {
    apiKey: "AIzaSyA3wRBK8Axd-cClnNaOYg1hhUH8hDD-Z-U",
    authDomain: "nome-7eaf2.firebaseapp.com",
    databaseURL: "https://nome-7eaf2-default-rtdb.firebaseio.com",
    projectId: "nome-7eaf2",
    storageBucket: "nome-7eaf2.appspot.com",
    messagingSenderId: "272170780482",
    appId: "1:272170780482:web:6a2e92f41b22c9ab71aadb"
};

firebase.initializeApp(firebaseConfig);
  
var database = firebase.database();
  
function get() {
    var grid = document.getElementById('grid');

    var item_ref = database.ref('realTime/');

    item_ref.on('value', function(snapshot) {
        var data = snapshot.val();

        grid.innerHTML = '';

        if (data) {       
          var imgElement = document.getElementById('imgLight');

          if (!imgElement) {
            imgElement = document.createElement('img');
            imgElement.id = 'imgLight';

            document.getElementById('img').appendChild(imgElement);
          }

          if (data.Luminosidade === 'Escura' || data.Luminosidade === 'Bem Escura') {
            imgElement.src = 'lightbulb-off.svg';
          } else {
            imgElement.src = 'lightbulb.svg';
          }

          const tabela = document.createElement('table');
          const thead = document.createElement('thead');
          const tbody = document.createElement('tbody');

          for (const key in data) {
            if (data.hasOwnProperty(key)) {
              const linha = document.createElement('tr');
              const celulaChave = document.createElement('td');
              const celulaValor = document.createElement('td');

              celulaChave.innerText = key;
              celulaValor.innerText = data[key];

              linha.appendChild(celulaChave);
              linha.appendChild(celulaValor);

              tbody.appendChild(linha);
            }
          }

          tabela.appendChild(thead);
          tabela.appendChild(tbody);

          document.getElementById('grid').appendChild(tabela);

        } else {
          alert('Nenhum resultado encontrado para o ID: ' + id);
        }

        if (data.Luminosidade === 'Clara' && data.Movimento === 'Não' || data.Luminosidade === 'Bem Clara' && data.Movimento === 'Não') {
          swal('A luz está acessa e não há ninguém presente na sala!');
        }
        console.log(data);
    });
}


function handleKeyPress(event) {
  if (event.keyCode === 13) {
    get();
  }
}
