import tensorflow as tf

hello = tf.constant('Hello,TensorFlow!')

sess=tf.Session()
#Execute session and run hello
print (sess.run(hello))
