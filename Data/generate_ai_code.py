import csv
import os
from openai import OpenAI
import re

api_key = os.environ.get('OPENAI_API_KEY')
prompt = "the output should be only a well commented C code solution of the following problem statement, the output is only the raw C code"

def generate_code(problem_statement):
    client = OpenAI(
        api_key=api_key,
    )

    chat_completion = client.chat.completions.create(
        messages=[
            {
                "role": "system",
                "content": prompt,
            },
            {
                "role": "user",
                "content": problem_statement,
            }
        ],
        model="gpt-3.5-turbo",
    )
    return chat_completion.choices[0].message.content

def extract_code_c(text,fname=None):
    """
    Extracts C code from api response

    Args:
    text (str): API response

    Returns:
    str: C code
    """
    # Regular expression to match code between ```c``` and ``` ```
    pattern = r'```c(.*?)```'
    match = re.search(pattern, text, re.DOTALL)
    
    if match:
        return match.group(1).strip()
    else:
        if fname:print(fname)
        raise ValueError


if __name__ == '__main__':
    with open('problem_descriptions.csv', 'r') as file:
        reader = csv.reader(file)
        problems = list(reader)[1:]

    for problem in problems:
        problem_statement = problem[0]
        problem_id = problem[1]
        if f"{problem_id}.c" in os.listdir('codes'):
            continue
        code = generate_code(problem_statement)
        print(f"Generated code for problem {problem_id}")
        code = extract_code_c(code,problem_id)

        with open(f'ai_generated_codes/ai_generated_{problem_id}.c', 'w') as file:
            file.write(code)


        

