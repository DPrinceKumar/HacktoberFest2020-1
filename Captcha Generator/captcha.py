#Code By Amey Band


from captcha.audio import AudioCaptcha
from captcha.image import ImageCaptcha

image = ImageCaptcha()
data = image.generate('12AFGcvd')
image.write('12AFGcvd', 'op.png')

audio = AudioCaptcha()
data = audio.generate('59647834')
audio.write('59647834', 'op.wav')
