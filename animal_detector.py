from keras.models import load_model
from PIL import Image, ImageOps
import numpy as np
import cv2 


def cam_trig():
    label_dict={0:"Elephant",
    1:"Leopard",
    2:"Pig",
    3:"Monkey",
    4:"Deer",
    5:"Jaguar",
    6:"Rhinoceros",
    7:"Snake",
    8:"Tiger",
    9:"Fox",
    10:"Bear",
    11:"Crocodile"
	}
    model = load_model('/home/kirito/Documents/Capstone/model_keras/forest_animal_detection_model.h5')
    vid = cv2.VideoCapture(0)
    frame_count=0
    while(True):
        ret, frame = vid.read()
        frame_count+=1
        #cv2.imshow('frame', frame)
        if(not(frame_count%10)):
            data = np.ndarray(shape=(1, 224, 224, 3), dtype=np.float32)
            image = frame
            size = (224, 224)
            image = cv2.resize(image,size)
            image_array = np.asarray(image)
            normalized_image_array = (image_array.astype(np.float32) / 127.0) - 1
            data[0] = normalized_image_array
            prediction = model.predict(data)

            print(np.argmax(prediction[0]))
            cv2.imwrite(label_dict[np.argmax(prediction[0])]+".jpg",frame)
            break
     
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break
    
    vid.release()

    cv2.destroyAllWindows()
    
    

cam_trig()