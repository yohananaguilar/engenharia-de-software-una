# Engenharia de Software UNA

Repositório acadêmico para organizar e versionar materiais do curso de Engenharia de Software na UNA, com foco em atividades, projetos e resumos separados por semestre e disciplina.

## Sobre

Este repositório reúne a trilha de estudos da graduação e funciona como histórico técnico da evolução ao longo dos semestres.

Objetivos principais:

- Centralizar entregas e materiais de apoio em um único lugar.
- Manter organização consistente por semestre e UC.
- Facilitar revisões para provas, trabalhos e projetos futuros.
- Registrar evolução prática em programação, sistemas e engenharia de software.

## Estrutura geral

```text
semestres/
	1-semestre/
	2-semestre/
	3-semestre/
	4-semestre/
```

Dentro de cada disciplina, a convenção é:

- atividades/
- projetos/
- resumos/

## Navegação rápida

### Semestres

- [1º semestre](semestres/1-semestre/README.md)
- [2º semestre](semestres/2-semestre/README.md)
- [3º semestre](semestres/3-semestre/README.md)
- [4º semestre](semestres/4-semestre/README.md)

### UCs atuais em destaque (4º semestre)

- [Organização de Computadores](semestres/4-semestre/organizacao-de-computadores/README.md)
- [Sistemas Operacionais](semestres/4-semestre/sistemas-operacionais/README.md)

### Projeto em destaque

- [Atividade Prática ESP32 com FreeRTOS](semestres/4-semestre/organizacao-de-computadores/atividades/atividade-pratica-esp32-freertos/README.md)

## Conteúdo por semestre

- 1º semestre
	- Fenômenos Elétricos, Magnéticos e Oscilatórios
	- Modelagem e Simulação de Sistemas Elétricos e Magnéticos
	- Vida e Carreira
- 2º semestre
	- Análise de Fenômenos Físicos da Natureza
	- Medição em Ciências e Representação Gráfica
- 3º semestre
	- Análise de Dados e Big Data
	- Inteligência Artificial
- 4º semestre
	- Organização de Computadores
	- Sistemas Operacionais

## Convenções deste repositório

- Nomes de pastas em minúsculas e com hífen.
- Uma pasta por disciplina dentro de cada semestre.
- Uma pasta por entrega quando houver múltiplos arquivos relacionados.
- Cada disciplina deve ter README próprio com contexto e links internos.

## Política de PDFs

Este repositório aceita PDFs de enunciado e entrega final.

Padrão recomendado por atividade:

- enunciado/arquivo-enunciado.pdf
- entrega/arquivo-entrega-final.pdf

Boas práticas:

- Evitar armazenar revisões intermediárias de PDFs.
- Priorizar apenas versão final para reduzir crescimento do histórico.
- Se houver grande volume de binários, considerar Git LFS no futuro.

Referência prática:

- [Validador de PDFs em Sistemas Operacionais](semestres/4-semestre/sistemas-operacionais/atividades/gerar_pdfs_entrega.py)

## Tecnologias e formatos utilizados

- Python
- Arduino/ESP32
- FreeRTOS
- Wokwi
- Markdown
- PDF

## Como utilizar

1. Escolha o semestre.
2. Acesse a disciplina desejada.
3. Navegue entre atividades, projetos e resumos.
4. Leia o README local para contexto específico de cada material.

## Organização recomendada para novas entregas

Modelo sugerido:

```text
disciplina/
	atividades/
		atividade-n/
			enunciado/
			entrega/
			README.md
```

## Roadmap acadêmico do repositório

- Manter atualização contínua a cada nova atividade e projeto.
- Padronizar READMEs de disciplinas e entregas.
- Expandir documentação técnica dos projetos mais relevantes.

## Status

Repositório em evolução contínua durante a graduação.

## Autor

Estudante de Engenharia de Software na UNA.

## Licença

Sem licença definida no momento.
