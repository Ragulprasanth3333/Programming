from PIL import Image,ImageEnhance,ImageFilter
import os
path = './img'
pathout = './imgresult'
for i in os.listdir(path):
    img = Image.open(f"{path}/{i}")
    edit = img.filter(ImageFilter.SHARPEN).rotate(90)
    factor = 2
    enhancer = ImageEnhance.Contrast(edit)
    edit = enhancer.enhance(factor)
    clean = os.path.splitext(i)[0]
    edit.save(f"{pathout}/{clean}_edited.jpg")