import tensorflow as tf
x_data = [1.,2.,3.]
y_data = [1.,2.,3.]

w = tf.Variable(tf.random_uniform([1],-10.0,10.0))

x = tf.placeholder(tf.float32) 
y = tf.placeholder(tf.float32)
#H = W*x+b
hypothesis = w * x 

cost = tf.reduce_mean(tf.square(hypothesis - y))
descent = w-tf.mul(0.1,tf.reduce_mean(tf.mul((tf.mul(w,x)-y),x)))
update = w.assign(descent)
#Before starting 
init = tf.initialize_all_variables()

sess = tf.Session()
sess.run(init)
print("Hello C world")
for step in range(20):
  sess.run(update,feed_dict={x:x_data,y:y_data})
  print(step,sess.run(cost,feed_dict={x:x_data,y:y_data}),sess.run(w))
print(sess.run(hypothesis,feed_dict={x:5}))
print(sess.run(hypothesis,feed_dict={x:2.5}))
