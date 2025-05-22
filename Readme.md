# 🏴‍☠️ Caça ao Tesouro Numérico

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![License](https://img.shields.io/badge/License-MIT-yellow.svg?style=for-the-badge)
![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20Linux%20%7C%20macOS-lightgrey?style=for-the-badge)

> Um jogo de aventura em terminal onde você é um caçador de tesouros em busca de riquezas perdidas! 💎

## 📖 Sobre o Projeto

**Caça ao Tesouro Numérico** é um jogo desenvolvido em linguagem C que combina estratégia, sorte e habilidade de dedução. O jogador assume o papel de um aventureiro que deve encontrar tesouros escondidos usando apenas coordenadas numéricas e pistas inteligentes.

### 🎯 Objetivo

Encontre o maior número possível de tesouros, avance pelos níveis crescentes de dificuldade e torne-se uma **Lenda dos Caçadores**!

## ✨ Características Principais

### 🎮 Mecânicas de Jogo
- **Sistema de Níveis Infinitos**: Dificuldade progressiva a cada tesouro encontrado
- **Gerenciamento de Vidas**: 3 vidas para usar estrategicamente
- **Sistema de Pontuação Dinâmica**: Recompensas maiores para eficiência
- **Dicas Inteligentes**: Feedback de proximidade e direção

### 🛠️ Recursos Técnicos
- ✅ Desenvolvido apenas com estruturas básicas do C
- ✅ Uso de loops (`for`, `while`) e condicionais
- ✅ Geração aleatória de coordenadas
- ✅ Interface rica com emojis e feedback visual
- ✅ Sistema de validação de entrada robusto

## 🚀 Como Jogar

### Instalação e Execução

```bash
# Clone o repositório
git clone https://github.com/marconesdb/Jogo_em_C.git

# Entre no diretório
cd Jogo_em_C

# Compile o programa
gcc -o jogo main.c

# Execute o jogo
./Jogo_em_C
```

### 📱 Interface do Jogo

```
=================================================
    🏴‍☠️ CAÇA AO TESOURO NUMÉRICO 🏴‍☠️
=================================================

🗺️  NÍVEL 1 - Procurando Tesouro #1
❤️  Vidas restantes: 3
💰 Pontuação atual: 0 pontos

🔍 Um tesouro está escondido em algum lugar entre 1 e 25!
⚡ Você tem 5 tentativas para encontrá-lo.

🎯 Tentativa 1/5 - Digite sua coordenada: 15
🌡️  Quente! Você está se aproximando!
↗️  Dica: Tente um número MAIOR!
```

## 🎲 Como Funciona

### Sistema de Dicas

O jogo fornece **dois tipos de feedback** após cada tentativa:

#### 🌡️ **Dicas de Proximidade**
- 🔥 **Muito Quente**: Distância ≤ 2 números
- 🌡️ **Quente**: Distância ≤ 5 números  
- 😐 **Morno**: Distância ≤ 10 números
- 🧊 **Frio**: Distância > 10 números

#### 🧭 **Dicas Direcionais**
- ↗️ **"Tente um número MAIOR"**: O tesouro está à frente
- ↙️ **"Tente um número MENOR"**: O tesouro está atrás

### 📈 Progressão de Níveis

| Nível | Range de Busca | Tentativas | Multiplicador |
|-------|----------------|------------|---------------|
| 1     | 1 - 25         | 5          | 1x            |
| 2     | 1 - 40         | 5          | 2x            |
| 3     | 1 - 55         | 6          | 3x            |
| 4     | 1 - 70         | 6          | 4x            |
| ...   | +15 por nível  | +0.5       | +1x           |

### 💰 Sistema de Pontuação

```
Pontos = (100 × Nível) ÷ Tentativas Usadas
```

**Exemplos:**
- Nível 3, encontrado na 1ª tentativa = **300 pontos** 🌟
- Nível 1, encontrado na 5ª tentativa = **20 pontos** 

## 🏆 Sistema de Rankings

Ao final do jogo, você receberá uma classificação baseada em sua performance:

| Pontuação | Classificação | Badge |
|-----------|---------------|-------|
| 1000+     | **Lenda dos Caçadores** | 🌟 |
| 500-999   | **Caçador Experiente** | ⭐ |
| 200-499   | **Aventureiro Corajoso** | 🎖️ |
| 1-199     | **Iniciante Promissor** | 🥉 |
| 0         | **Novato Determinado** | 🎯 |

## 🎯 Estratégias e Dicas

### 💡 **Dicas para Pontuação Alta**
1. **Seja Eficiente**: Menos tentativas = mais pontos
2. **Use as Dicas**: Combine proximidade + direção para localizar rapidamente
3. **Gerencie Vidas**: Às vezes é melhor arriscar para conseguir mais pontos
4. **Método de Divisão**: Comece pelo meio do range e vá dividindo

### 🧠 **Estratégia Recomendada**
```
Range: 1-25, Tesouro em posição desconhecida

Tentativa 1: 13 (meio) → "Quente, tente MAIOR"
Tentativa 2: 19 (meio da parte alta) → "Muito quente, tente MENOR"  
Tentativa 3: 16 → "Muito quente, tente MAIOR"
Tentativa 4: 18 → 🎉 TESOURO ENCONTRADO!
```

## 🛠️ Aspectos Técnicos

### Estruturas Utilizadas

- **Loops While**: Controle principal do jogo e sistema de tentativas
- **Loops For**: Efeitos visuais e animações de texto
- **Condicionais**: Sistema de dicas, validações e pontuação
- **Random**: Geração aleatória das posições dos tesouros

### Algoritmos Implementados

```c
// Cálculo de distância
int distancia = abs(palpite_jogador - tesouro_posicao);

// Fórmula de pontuação
int pontos = (100 * nivel) / tentativas_usadas;

// Progressão de dificuldade
int range_max = 10 + (nivel * 15);
```

## 📊 Estatísticas do Jogo

Durante e após o jogo, você pode acompanhar:

- 💰 **Pontuação Total**: Acumulada durante toda a partida
- 💎 **Tesouros Encontrados**: Número total de sucessos
- 🎚️ **Nível Alcançado**: Maior nível atingido
- ❤️ **Vidas Restantes**: Status atual de saúde
- 🎯 **Eficiência**: Média de tentativas por tesouro

## 🎨 Recursos Visuais

### Interface Rica
- 🎨 **Emojis Contextuais**: Feedback visual imediato
- 🌈 **Mensagens Coloridas**: Diferentes tipos de informação
- ✨ **Animações de Texto**: Celebração de conquistas
- 📊 **Estatísticas em Tempo Real**: Acompanhamento do progresso

### Exemplo de Celebração
```
✨ ✨ ✨ TESOURO ENCONTRADO! ✨ ✨ ✨

🎉 PARABÉNS! Você encontrou o tesouro!
💎 Tesouro #3 coletado com sucesso!
⭐ Você ganhou 150 pontos!
```

## 🏗️ Arquitetura do Código

```
main.c
├── Inicialização (srand, variáveis)
├── Loop Principal do Jogo
│   ├── Configuração do Nível
│   ├── Geração Aleatória do Tesouro  
│   ├── Loop de Tentativas
│   │   ├── Entrada do Usuário
│   │   ├── Validação
│   │   ├── Sistema de Dicas
│   │   └── Verificação de Sucesso
│   └── Controle de Vidas/Continuação
└── Estatísticas Finais e Classificação
```

## 🎓 Propósito Educacional

Este projeto foi desenvolvido como parte de um trabalho acadêmico com as seguintes restrições técnicas:

- ❌ **Sem uso de**: Arrays, matrizes, funções, procedimentos
- ✅ **Apenas**: Estruturas básicas (loops, condicionais, random)
- 🎯 **Objetivo**: Demonstrar criatividade dentro de limitações técnicas

## 🤝 Contribuindo

Contribuições são bem-vindas! Se você tem ideias para melhorar o jogo:

1. Fork o projeto
2. Crie sua branch (`git checkout -b feature/MinhaFeature`)
3. Commit suas mudanças (`git commit -m 'Adiciona MinhaFeature'`)
4. Push para a branch (`git push origin feature/MinhaFeature`)
5. Abra um Pull Request

### 💡 Ideias para Contribuição
- Novos tipos de dicas
- Diferentes modos de jogo
- Melhorias na interface
- Otimizações de performance
- Tradução para outros idiomas

## 📝 Licença

Este projeto está sob a licença MIT. Veja o arquivo [LICENSE](LICENSE) para detalhes.

## 👤 Autor

**[Marcone Silva de Brito]**
- GitHub: [@seu-usuario](https://github.com/marconesdb)
- LinkedIn: [Seu Perfil](https://www.linkedin.com/in/marconesb/)
- Email: marconebritt@gmail.com

## 🙏 Agradecimentos

- Inspiração em jogos clássicos de adivinhação
- Comunidade C/C++ pela documentação
- Colegas de curso pelas discussões técnicas

---

### 🎮 Pronto para a Aventura?

```bash
git clone https://github.com/marconesdb
cd Jogo_em_C
gcc -o jogo main.c
./Jogo_em_C
```

**Boa sorte, caçador de tesouros! Que a fortuna esteja com você! 🏴‍☠️💎**

---

⭐ **Se você gostou do projeto, não esqueça de dar uma estrela!** ⭐