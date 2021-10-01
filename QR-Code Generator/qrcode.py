#import the module
import pyqrcode
import png

#define the qr_data
qr_data = 'http://amey23.github.io/portfolio/#home'

#create qrcode
qr_img = pyqrcode.create(qr_data)

#save the qrcode in png format with proper scaling
qr_img.png('QR-Code.png', scale= 20)
