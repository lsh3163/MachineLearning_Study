import tensorflow as tf
x_data = [1.,2.,3.]
y_data = [1.,2.,3.]

w = tf.Variable(tf.random_uniform([1],-1.0,1.0))
b = tf.Variable(tf.random_uniform([1],-1.0,1.0))
#H = W*x+b
hypothesis = w * x_data +b

cost = tf.reduce_mean(tf.square(hypothesis - y_data))

a = tf.Variable(0.1)
optimizer = tf.train.GradientDescentOptimizer(a)
train = optimizer.minimize(cost)
#Before starting 
init = tf.initialize_all_variables()

sess = tf.Session()
sess.run(init)
print("Hello C world")
for step in range(2001):
  sess.run(train)
  if step % 20 == 0:
    print (step,sess.run(cost),sess.run(w),sess.run(b))
