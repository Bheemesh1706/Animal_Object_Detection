from keras.models import load_model
from PIL import Image, ImageOps
import numpy as np
import cv2 

def msg_send():        
    account_sid = 'AC336340ba9b5c1193729cc4cbb8d9f5d6' 
    auth_token = 'd7253757cdaa8a3459007822654d595f' 

    client = Client(account_sid, auth_token) 
    
    message = client.messages.create( 
                                from_='whatsapp:+14155238886',
                                body='This is alert',      
                                to='whatsapp:+916380387570' 
                            ) 
    
    print(message.sid)

def cam_trig():
    vid = cv2.VideoCapture(0)
    frame_count=0
    while(True):
            
        ret, frame = vid.read()
        frame_count+=1
        cv2.imshow('frame', frame)
        if(not(frame_count%10)):
            cv2.imwrite("frame_count"+str(frame_count/10)+".jpg",frame)
            break
     
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break
    
    vid.release()

    cv2.destroyAllWindows()
    
    msg_send()

model = load_model('model_keras/forest_animal_detection_model.h5')

data = np.ndarray(shape=(1, 224, 224, 3), dtype=np.float32)
image = Image.open('Images/e1.jpeg')
size = (224, 224)
image = ImageOps.fit(image, size, Image.ANTIALIAS)


image_array = np.asarray(image)
normalized_image_array = (image_array.astype(np.float32) / 127.0) - 1
data[0] = normalized_image_array
prediction = model.predict(data)

print(np.argmax(prediction[0]))
