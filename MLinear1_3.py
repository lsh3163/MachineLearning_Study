import tensorflow as tf

x_data = [[1.,1.,1.,1.,1.],[0.,2.,0.,4.,0.],[1.,0.,3.,0.,5.]]
y_data = [1,2,3,4,5]
w = tf.Variable(tf.random_uniform([1,3],-1.0,1.0))
b = tf.Variable(tf.random_uniform([1],-1.0,1.0))
hypothesis = tf.matmul(w,x_data)
cost = tf.reduce_mean(tf.square(hypothesis-y_data))
a = tf.Variable(0.1)
optimizer = tf.train.GradientDescentOptimizer(a)
train = optimizer.minimize(cost)
init = tf.initialize_all_variables()
sess = tf.Session()
sess.run(init)
for step in range(2001):
  sess.run(train)
  if step % 20 ==0:
    print(step,sess.run(cost),sess.run(w),sess.run(b))
