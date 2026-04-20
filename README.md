# Engenharia de Software | Centro Universitário UNA

[![Status](https://img.shields.io/badge/status-em%20evolucao-1f6feb)](README.md)
[![Perfil](https://img.shields.io/badge/perfil-portfolio%20academico-0a7ea4)](README.md)
[![Python](https://img.shields.io/badge/Python-3776AB?logo=python&logoColor=white)](README.md)
[![C/C++](https://img.shields.io/badge/C%2FC%2B%2B-00599C?logo=cplusplus&logoColor=white)](README.md)
[![Arduino](https://img.shields.io/badge/Arduino-00979D?logo=arduino&logoColor=white)](README.md)
[![ESP32](https://img.shields.io/badge/ESP32-333333)](README.md)
[![FreeRTOS](https://img.shields.io/badge/FreeRTOS-3A75C4)](README.md)
[![Markdown](https://img.shields.io/badge/Markdown-000000?logo=markdown&logoColor=white)](README.md)

Repositório acadêmico centralizado para organização, versionamento e documentação de materiais, atividades e projetos da graduação em Engenharia de Software.

Este espaço funciona como registro histórico e portfólio técnico da evolução ao longo dos semestres, com foco prático em desenvolvimento de software, fundamentos de sistemas e arquitetura computacional.

## Objetivos do repositório

- Centralizar entregas, códigos e materiais de apoio em um único local.
- Padronizar a organização por semestre e unidade curricular.
- Facilitar rastreabilidade de estudos, revisões e evolução técnica.
- Construir um portfólio acadêmico consistente para uso profissional.

## Estrutura geral e navegação

A arquitetura do repositório é organizada de forma cronológica por semestre. Em cada unidade curricular, a convenção padrão separa o conteúdo em atividades, projetos e resumos.

```text
semestres/
  1-semestre/
  2-semestre/
  3-semestre/
  4-semestre/
```

Convenção por disciplina:

- atividades/
- projetos/
- resumos/

## Semestres

- [1º semestre](semestres/1-semestre/README.md)
- [2º semestre](semestres/2-semestre/README.md)
- [3º semestre](semestres/3-semestre/README.md)
- [4º semestre](semestres/4-semestre/README.md)

## Unidades curriculares em destaque (4º semestre)

- [Sistemas Operacionais](semestres/4-semestre/sistemas-operacionais/README.md): processos, organização de memória, estruturas de atividade e validação de entregas.
- [Organização de Computadores](semestres/4-semestre/organizacao-de-computadores/README.md): arquitetura de hardware, lógica digital e simulações.

## Projeto em destaque

- [Atividade Prática ESP32 com FreeRTOS](semestres/4-semestre/organizacao-de-computadores/atividades/atividade-pratica-esp32-freertos/README.md)

Aplicação prática de concorrência, controle por eventos e multitarefa em sistemas embarcados com ESP32, Arduino e Wokwi.

## Conteúdo acadêmico por semestre

### 1º semestre

- Fenômenos Elétricos, Magnéticos e Oscilatórios
- Modelagem e Simulação de Sistemas Elétricos e Magnéticos
- Vida e Carreira

### 2º semestre

- Análise de Fenômenos Físicos da Natureza
- Medição em Ciências e Representação Gráfica

### 3º semestre

- Análise de Dados e Big Data
- Inteligência Artificial

### 4º semestre

- Organização de Computadores
- Sistemas Operacionais

## Tecnologias e ferramentas aplicadas

- Linguagens: Python, C/C++ (Arduino)
- Sistemas e hardware: ESP32, FreeRTOS, Wokwi
- Documentação e organização: Markdown, PDF

## Normas e convenções do repositório

1. Nomenclatura de pastas e arquivos em letras minúsculas e separadas por hífen.
2. Cada disciplina mantém README próprio com contexto e links internos.
3. Cada entrega deve ficar isolada em pasta específica quando houver múltiplos arquivos.
4. Estrutura interna recomendada de atividades: enunciado e entrega.

## Política de arquivos PDF

Este repositório aceita PDFs de enunciado e entrega final.

Padrão recomendado por atividade:

- enunciado/arquivo-enunciado.pdf
- entrega/arquivo-entrega-final.pdf

Boas práticas adotadas:

- Manter somente versões finais, evitando revisões intermediárias redundantes.
- Preservar nomenclatura padronizada para facilitar busca e auditoria.
- Considerar Git LFS futuramente apenas se o volume de binários crescer de forma relevante.

Validação automatizada de estrutura de PDFs:

- [Script de validação](semestres/4-semestre/sistemas-operacionais/atividades/gerar_pdfs_entrega.py)

## Como utilizar este repositório

1. Acesse o semestre desejado.
2. Escolha a unidade curricular.
3. Navegue entre atividades, projetos e resumos.
4. Consulte o README local para detalhes de cada entrega.

## Modelo recomendado para novas entregas

```text
disciplina/
  atividades/
    atividade-n/
      enunciado/
      entrega/
      README.md
```

## Evolução esperada

- Atualização contínua com novas atividades e projetos.
- Expansão de documentação técnica nas entregas mais relevantes.
- Consolidação gradual como portfólio acadêmico e profissional.

## Status

Repositório em evolução contínua durante a graduação.

## Autor

Yohanan Aguilar

Estudante de Engenharia de Software na UNA.

## Licença

Sem licença definida até o momento.
