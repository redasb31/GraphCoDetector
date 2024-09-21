from bs4 import BeautifulSoup
import os
from pylatexenc.latex2text import LatexNodes2Text
import csv


def extract_problem_description(html_content):
    """
    Extracts the problem description from the specified html content.

    Args:
        html_content (str): The html content containing the problem description.

    Returns:
        str: The problem description.
    """
    soup = BeautifulSoup(html_content, 'html.parser')
    
    # Locate the "Template for C" heading
    template_heading = soup.find('h2', string="Template for C")

    if not template_heading:
        #check if the first paragraph is in english not korean
        #find all elements of depth 1
        all_paragraphs = soup.find_all('p')
        
        if all_paragraphs:
            all_paragraphs = '\n'.join(part.text.strip() for part in all_paragraphs)
            if all(ord(x) < 256 for x in all_paragraphs):
                return soup.text
        return None
    
    
    problem_description_parts = [element.text for element in template_heading.find_previous_siblings()][::-1]


    # Concatenate the text and pre elements
    problem_description = '\n'.join(part for part in problem_description_parts)
    
    return problem_description

def extract_problems_from_directory(directory):
    """
    Extracts problem descriptions from html files in the specified directory.

    Args:
        directory (str): The directory containing the html files.

    Returns:
        list: A list of problem descriptions extracted from the html files.
    """

    # Read the html files from the directory
    html_files = [file for file in sorted(os.listdir(directory)) if file.endswith('.html')]

    # Extract the problem descriptions from the html files
    problem_descriptions = []
    for html_file in html_files:
        with open(os.path.join(directory, html_file), 'r') as file:
            print(html_file)
            html_content = file.read()
            problem_description = extract_problem_description(html_content)
            if not problem_description:
                print(f"Could not find problem description in {html_file}")
            else:
                problem_descriptions.append([LatexNodes2Text().latex_to_text(problem_description),html_file.split('.')[0]])

    return problem_descriptions

def write_to_csv(problems,fname = 'problem_descriptions.csv'):
    """
    Writes the problem descriptions to a csv file.

    Args:
        problems (list): A list of problem descriptions.
    """
    with open(fname, 'w', newline='') as file:
        writer = csv.writer(file)
        writer.writerow(["problem_description","problem_id"])
        writer.writerows(problems)

if __name__ == "__main__":
    problems = extract_problems_from_directory("problem_descriptions")
    write_to_csv(problems)
