from pathlib import Path
import os

my_file = Path("main")
if my_file.is_file():
    # print("exist")
    os.system("echo exist")
    os.system("rm -f main")
else:
    # print("not exist")
    os.system("echo not exist")

os.system("g++ Logger.cpp main.cpp Time.cpp -o main")

my_file = Path("main")
if my_file.is_file():
    os.system("./main")