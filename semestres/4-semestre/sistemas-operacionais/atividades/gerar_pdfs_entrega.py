from pathlib import Path


BASE_DIR = Path(__file__).resolve().parent

EXPECTED_FILES = {
    "atividade-iii": [
        "enunciado/atividade-iii-enunciado.pdf",
        "entrega/atividade-iii-entrega-final.pdf",
    ],
    "atividade-iv": [
        "enunciado/atividade-iv-enunciado.pdf",
        "entrega/atividade-iv-entrega-final.pdf",
    ],
}


def main() -> None:
    for folder_name, expected_files in EXPECTED_FILES.items():
        folder_path = BASE_DIR / folder_name
        existing_pdfs = sorted(
            str(path.relative_to(folder_path)).replace("\\", "/")
            for path in folder_path.rglob("*.pdf")
        )
        missing_files = [name for name in expected_files if name not in existing_pdfs]
        extra_files = [name for name in existing_pdfs if name not in expected_files]

        print(f"Pasta: {folder_name}")

        if missing_files:
            print("  PDFs ausentes:")
            for file_name in missing_files:
                print(f"  - {file_name}")
        else:
            print("  PDFs esperados presentes.")

        if extra_files:
            print("  PDFs extras:")
            for file_name in extra_files:
                print(f"  - {file_name}")
        else:
            print("  Nenhum PDF extra.")


if __name__ == "__main__":
    main()