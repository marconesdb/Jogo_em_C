#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Inicialização do gerador de números aleatórios
    srand(time(NULL));
    
    // Variáveis principais do jogo
    int pontuacao = 0;
    int nivel = 1;
    int vidas = 3;
    int tesouros_encontrados = 0;
    int jogar_novamente = 1;
    
    // Variáveis para controle de jogo
    int tesouro_posicao, palpite_jogador;
    int tentativas, max_tentativas;
    int dica_min, dica_max;
    int multiplicador_pontos;
    
    printf("=================================================\n");
    printf("    🏴‍☠️ CAÇA AO TESOURO NUMÉRICO 🏴‍☠️\n");
    printf("=================================================\n");
    printf("Bem-vindo, aventureiro! Você é um caçador de\n");
    printf("tesouros em busca de riquezas perdidas!\n\n");
    printf("📜 REGRAS DO JOGO:\n");
    printf("• Você terá pistas para encontrar tesouros\n");
    printf("• Cada nível fica mais difícil\n");
    printf("• Você tem 3 vidas para completar sua jornada\n");
    printf("• Ganhe pontos encontrando tesouros rapidamente!\n");
    printf("=================================================\n\n");
    
    // Loop principal do jogo
    while (jogar_novamente == 1 && vidas > 0) {
        printf("🗺️  NÍVEL %d - Procurando Tesouro #%d\n", nivel, tesouros_encontrados + 1);
        printf("❤️  Vidas restantes: %d\n", vidas);
        printf("💰 Pontuação atual: %d pontos\n\n", pontuacao);
        
        // Configuração do nível atual
        // Cada nível aumenta a dificuldade
        dica_min = 1;
        dica_max = 10 + (nivel * 15); // Aumenta o range a cada nível
        max_tentativas = 5 + (nivel / 2); // Mais tentativas em níveis avançados
        multiplicador_pontos = nivel; // Mais pontos em níveis altos
        
        // Gera posição aleatória do tesouro
        tesouro_posicao = (rand() % (dica_max - dica_min + 1)) + dica_min;
        
        printf("🔍 Um tesouro está escondido em algum lugar entre %d e %d!\n", dica_min, dica_max);
        printf("⚡ Você tem %d tentativas para encontrá-lo.\n\n", max_tentativas);
        
        // Loop de tentativas para encontrar o tesouro
        tentativas = 0;
        int tesouro_encontrado = 0;
        
        while (tentativas < max_tentativas && tesouro_encontrado == 0) {
            printf("🎯 Tentativa %d/%d - Digite sua coordenada: ", tentativas + 1, max_tentativas);
            scanf("%d", &palpite_jogador);
            
            // Validação da entrada
            if (palpite_jogador < dica_min || palpite_jogador > dica_max) {
                printf("⚠️  Coordenada inválida! Digite um número entre %d e %d.\n\n", dica_min, dica_max);
                continue;
            }
            
            tentativas++;
            
            // Verifica se encontrou o tesouro
            if (palpite_jogador == tesouro_posicao) {
                tesouro_encontrado = 1;
                tesouros_encontrados++;
                
                // Cálculo da pontuação baseado na eficiência
                int pontos_ganhos = (100 * multiplicador_pontos) / tentativas;
                pontuacao += pontos_ganhos;
                
                printf("\n🎉 PARABÉNS! Você encontrou o tesouro!\n");
                printf("💎 Tesouro #%d coletado com sucesso!\n", tesouros_encontrados);
                printf("⭐ Você ganhou %d pontos!\n", pontos_ganhos);
                
                // Efeito visual de comemoração
                printf("\n");
                for (int i = 0; i < 3; i++) {
                    printf("✨ ");
                }
                printf("TESOURO ENCONTRADO! ");
                for (int i = 0; i < 3; i++) {
                    printf("✨ ");
                }
                printf("\n\n");
                
            } else {
                // Fornece dicas baseadas na distância
                int distancia = (palpite_jogador > tesouro_posicao) ? 
                               (palpite_jogador - tesouro_posicao) : 
                               (tesouro_posicao - palpite_jogador);
                
                if (distancia <= 2) {
                    printf("🔥 Muito quente! O tesouro está bem próximo!\n");
                } else if (distancia <= 5) {
                    printf("🌡️  Quente! Você está se aproximando!\n");
                } else if (distancia <= 10) {
                    printf("😐 Morno... O tesouro não está tão perto.\n");
                } else {
                    printf("🧊 Frio! O tesouro está distante.\n");
                }
                
                // Dica direcional
                if (palpite_jogador < tesouro_posicao) {
                    printf("↗️  Dica: Tente um número MAIOR!\n");
                } else {
                    printf("↙️  Dica: Tente um número MENOR!\n");
                }
                
                printf("💭 Tentativas restantes: %d\n\n", max_tentativas - tentativas);
            }
        }
        
        // Verifica se não encontrou o tesouro
        if (tesouro_encontrado == 0) {
            vidas--;
            printf("💀 Que pena! Você não conseguiu encontrar o tesouro.\n");
            printf("📍 O tesouro estava na coordenada %d.\n", tesouro_posicao);
            printf("💔 Você perdeu uma vida!\n\n");
            
            if (vidas > 0) {
                printf("🔄 Mas não desista! Você ainda tem %d vida(s).\n", vidas);
                printf("🎯 Vamos tentar novamente!\n\n");
            }
        } else {
            // Avança para o próximo nível
            nivel++;
            printf("🚀 Prepare-se! O próximo nível será mais desafiador!\n\n");
        }
        
        // Pergunta se quer continuar (só se ainda tiver vidas)
        if (vidas > 0) {
            int opcao;
            printf("====================================\n");
            printf("O que você deseja fazer?\n");
            printf("1 - Continuar a aventura\n");
            printf("2 - Encerrar e ver pontuação final\n");
            printf("Escolha (1 ou 2): ");
            scanf("%d", &opcao);
            
            if (opcao == 2) {
                jogar_novamente = 0;
            }
            printf("\n");
        }
    }
    
    // Resultado final do jogo
    printf("=================================================\n");
    printf("           🏁 FIM DA AVENTURA! 🏁\n");
    printf("=================================================\n");
    
    if (vidas == 0) {
        printf("💀 Suas vidas acabaram, mas você lutou bravamente!\n");
    } else {
        printf("🎯 Você escolheu encerrar sua aventura!\n");
    }
    
    printf("\n📊 ESTATÍSTICAS FINAIS:\n");
    printf("🏆 Pontuação Total: %d pontos\n", pontuacao);
    printf("💎 Tesouros Encontrados: %d\n", tesouros_encontrados);
    printf("🎚️  Nível Alcançado: %d\n", nivel - 1);
    printf("❤️  Vidas Restantes: %d\n", vidas);
    
    // Sistema de classificação
    printf("\n🏅 CLASSIFICAÇÃO: ");
    if (pontuacao >= 1000) {
        printf("LENDA DOS CAÇADORES! 🌟\n");
    } else if (pontuacao >= 500) {
        printf("CAÇADOR EXPERIENTE! ⭐\n");
    } else if (pontuacao >= 200) {
        printf("AVENTUREIRO CORAJOSO! 🎖️\n");
    } else if (tesouros_encontrados > 0) {
        printf("INICIANTE PROMISSOR! 🥉\n");
    } else {
        printf("NOVATO DETERMINADO! 🎯\n");
    }
    
    printf("\n💭 Dica para próxima vez: Seja estratégico com suas\n");
    printf("   tentativas! Menos tentativas = mais pontos!\n");
    
    printf("\n🙏 Obrigado por jogar Caça ao Tesouro Numérico!\n");
    printf("=================================================\n");
    
    return 0;
}