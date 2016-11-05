#PlaceHolder
import tensorflow as tf
#Define tf parameter
a = tf.placeholder(tf.int16)
b = tf.placeholder(tf.int16)
#Define Function
add = tf.add(a,b)
mul = tf.mul(a,b)
with tf.Session() as sess:
  print("Addition with Variables: %i" % sess.run(add,feed_dict={a:2,b:3}))
  print("Multipication with Variables: %i" % sess.run(mul,feed_dict={a:2,b:3}))
