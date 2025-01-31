# 📘 Contador Digital com Interrupções e Matriz de LEDs

## 📌 Visão Geral  
Este projeto implementa um **contador de 0 a 9** usando uma matriz de LEDs controlada por um **Raspberry Pi Pico**. Dois botões permitem **incrementar** e **decrementar** o número exibido, enquanto um LED pisca **5 vezes por segundo** para indicar que o sistema está funcionando corretamente.  

## ⚙️ Como Funciona?  
- 🔼 **Botão 1 (GPIO 5):** Aumenta o número exibido (até 9).  
- 🔽 **Botão 2 (GPIO 6):** Diminui o número exibido (até 0).  
- 💡 **LED indicador (GPIO 13):** Pisca constantemente para indicar funcionamento.  
- ⏳ **Debounce eficiente:** Evita múltiplos cliques indesejados ao segurar o botão.  

## 🎯 Objetivo do Projeto  
Este sistema demonstra como **controlar uma matriz de LEDs de forma eficiente**, utilizando **interrupções** para garantir uma resposta rápida aos botões sem prejudicar o funcionamento do restante do código.  

## 🔍 Aplicações Práticas  
✅ Contadores numéricos (ex: placares, senhas de atendimento).  
✅ Interface simples para entrada de dados com botões físicos.  
✅ Controle de exibição em painéis de LEDs.  
✅ Base para projetos maiores de automação e eletrônica embarcada.  

## 💡 Benefícios do Projeto  
✔️ **Baixo consumo de energia** – utiliza apenas os componentes essenciais.  
✔️ **Resposta rápida** – botões funcionam instantaneamente sem atrasos.  
✔️ **Código modular** – pode ser facilmente expandido para incluir novas funcionalidades.  
✔️ **Uso de interrupções** – garante eficiência sem a necessidade de polling contínuo.  

## 🚀 Como Usar?  
1️⃣ **Conecte** os botões e a matriz de LEDs ao Raspberry Pi Pico.  
2️⃣ **Carregue** o código no Pico usando o ambiente de desenvolvimento adequado.  
3️⃣ **Pressione os botões** para testar a mudança de números na matriz.  
4️⃣ **Observe o LED piscar**, garantindo que o sistema está ativo.  

## 🛠️ Requisitos  
- Raspberry Pi Pico  
- Matriz de LEDs  
- 2 botões de pressão  
- LED indicador  
- Fios jumpers  

## Link do video

-https://www.youtube.com/watch?v=tbygNRUj7eA



## 📜 Licença  
Este projeto é de código aberto e pode ser usado livremente para estudos e modificações.  

---

**🤖 Agora é só experimentar e personalizar conforme suas necessidades!** 😃  
