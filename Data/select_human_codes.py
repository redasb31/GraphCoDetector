import shutil
import os

selected = eval(open(os.path.join("human_codes",'selected.txt')).read())

for fname in selected:
    out_fname = "human_"+fname.split('/')[-1]
    shutil.copy( os.path.join("codenet_c_all_solutions",fname) , os.path.join("human_codes",out_fname))
    print(f"Copying {fname} to selected_codes/{out_fname}")

