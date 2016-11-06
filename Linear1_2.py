import tensorflow as tf
x_data = [1.,2.,3.]
y_data = [1.,2.,3.]

w = tf.Variable(tf.random_uniform([1],-1.0,1.0))
b = tf.Variable(tf.random_uniform([1],-1.0,1.0))

x = tf.placeholder(tf.float32) 
y = tf.placeholder(tf.float32)
#H = W*x+b
hypothesis = w * x +b

cost = tf.reduce_mean(tf.square(hypothesis - y))

a = tf.Variable(0.1)
optimizer = tf.train.GradientDescentOptimizer(a)
train = optimizer.minimize(cost)
#Before starting 
init = tf.initialize_all_variables()

sess = tf.Session()
sess.run(init)
print("Hello C world")
for step in range(2001):
  sess.run(train,feed_dict={x:x_data,y:y_data})
  if step % 20 == 0:
    print (step,sess.run(cost,feed_dict={x:x_data,y:y_data}),sess.run(w),sess.run(b))
print(sess.run(hypothesis,feed_dict={x:5}))
print(sess.run(hypothesis,feed_dict={x:2.5}))
