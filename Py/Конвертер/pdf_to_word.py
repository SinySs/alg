from tkinter import *
from tkinter import filedialog as fd
from pdf2docx import parse
import pathlib

def choseFile():
    name = fd.askopenfilename()
    ePath.config(state='normal')
    ePath.delete('1', END)
    ePath.insert('1', name)
    ePath.config(state='readonly')
    

def convert():
    pdfFile = ePath.get()
    wordFile = pathlib.Path(pdfFile)
    wordFile = wordFile.stem +'.docx'
    parse(pdfFile, wordFile)
    Label(root, text='Конвертация завершена', fg = 'lime', bg='black',
                   font = 'Arial 15 bold').pack()
    

root = Tk()
root.title('Конвертер PDF to Word')
root.geometry('400x300+500+300')
root.resizable(width = False, height = False)
root['bg'] = 'black'


btnEnter = Button(root, text='Выбрать PDF файл', font ='Arial 15 bold', 
       fg='lime', bg='black', command=choseFile).pack(pady=10)


lbPath = Label(root, text='Путь к файлу', fg = 'lime', bg='black',
               font = 'Arial 15 bold')
lbPath.pack()

ePath = Entry(root, width=50, state='readonly')
ePath.pack(pady=10)


btnConvert = Button(root, text='Конвертировать', fg = 'lime', bg='black',
               font = 'Arial 15 bold', command=convert)
btnConvert.pack(pady=10)

root.mainloop()
