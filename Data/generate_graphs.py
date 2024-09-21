import sys
import os
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__),'..','CPG')))

from generate_cpg import generate_cpg_for_dir

def generate_graphs():
    """
    Generates CPGs for all the AI-generated and Human written codes
    """
    generate_cpg_for_dir(directory='ai_generated_codes',out_dir="graphs",label=1)
    generate_cpg_for_dir(directory='human_codes',out_dir="graphs",label=0)

if __name__ == '__main__':
    generate_graphs()