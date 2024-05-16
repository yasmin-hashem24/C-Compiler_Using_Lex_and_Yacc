import os
import subprocess
import tkinter as tk
from tkinter import Button, scrolledtext
from tkinter import filedialog
from tkinter import messagebox



class MyWindow(tk.Frame):
    def __init__(self, master=None):
        super().__init__(master)
        self.master = master
        self.pack(expand=True, fill="both") 
        self.InitUI() 
        
    def InitUI(self):
        self.master.title("C/C++ compiler")
        self.master.geometry("500x300+480+100")
        self.bg = tk.PhotoImage(file = "back.png") 
        self.canvas1 = tk.Canvas(self.master, width = 400, height = 400) 
        self.canvas1.pack(fill = "both", expand = True)
        self.CreateUI()
            
    def CreateUI(self):
        self.canvas1.create_image(0, 0, image = self.bg, anchor = "nw") 
        self.canvas1.create_text(250, 30, text = "Welcome to our compiler", font=("Arial", 17,"bold"), fill="purple") 
        self.code_editor = scrolledtext.ScrolledText(self.canvas1, wrap=tk.WORD, bg="black", fg="yellow", font=("Consolas", 12), width=40, height=5,insertbackground='white')
        text_window = self.canvas1.create_window(70, 60, window=self.code_editor, anchor="nw")
        self.code_editor.focus_set()
        button1 = tk.Button(self.master, text="Compile code", fg="white", bg="purple", font=("Arial", 12, "bold"),borderwidth=0, width=13, command=self.compile_code)
        button1_canvas = self.canvas1.create_window(250, 179, anchor="nw", window=button1)
        button2 = tk.Button(self.master, text="Upload file", fg="white", bg="purple", font=("Arial", 12, "bold"),borderwidth=0, width=10, command=self.upload)
        button2_canvas = self.canvas1.create_window(133, 179, anchor="nw", window=button2)
    
    def compile_code(self):
        code = self.code_editor.get("1.0", "end")
        if not code.strip():
            messagebox.showerror("Input Error", "please enter your code")
            return
        file_path = "../testinput.txt"
        with open(file_path, "w") as f:
            f.write(code)
        subprocess.call(["../bas.exe", file_path])
        syntax_error_file = "../syntax_errors.txt"  
        semantic_error_file = "../semantic_errors.txt" 
        syntax_errors = None
        semantic_errors = None
        if os.path.exists(syntax_error_file):
            with open(syntax_error_file, "r") as f:
                syntax_errors = f.read().strip()

        if os.path.exists(semantic_error_file):
            with open(semantic_error_file, "r") as f:
                semantic_errors = f.read().strip()

        if syntax_errors :
            error_message = "Syntax Errors:\n{}\n".format(syntax_errors)
        if semantic_errors:
            if syntax_errors:
                error_message += "\nSemantic Errors:\n{}\n".format(semantic_errors)
                messagebox.showerror("Compilation Errors", error_message)
            else:
                error_message = "\nSemantic Errors:\n{}\n".format(semantic_errors)
                messagebox.showerror("Compilation Errors", error_message)
        else:
            messagebox.showerror("Compilation Errors", error_message)
        if not syntax_errors and not semantic_errors:
            print("Successful")

        
    def upload(self):
        filename = filedialog.askopenfilename(initialdir="/", title="Select file",
                                                filetypes=(("text files", "*.txt"), ("all files", "*.*")))
        if filename:
            with open(filename, "r") as file:
                lines = file.readlines()
                for line in lines:
                    self.code_editor.insert(tk.END, line)
        


m = tk.Tk()
m.resizable(False, False)
root=MyWindow(master=m)
root.mainloop()
