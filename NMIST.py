import tansorflow as tf

from tensorflow.examples.tutorials.mnist import input_data
mnist = input_data.read_data_sets('./samples/MNIST_data/', one_hot=True)

import tensorflow as tf

x = tf.placeholder(tf.float32, [None, 784])
//784*10의 행렬값
W = tf.Variable(tf.zeros([784, 10]))
//숫자의 종류 개수
b = tf.Variable(tf.zeros([10]))
//matrix 끼리 곱함
y = tf.nn.softmax(tf.matmul(x, W) + b)

y_ = tf.placeholder(tf.float32, [None, 10])
//Cost Function
cross_entropy = tf.reduce_mean(-tf.reduce_sum(y_ * tf.log(y), reduction_indices=[1]))
train_step = tf.train.GradientDescentOptimizer(0.5).minimize(cross_entropy)
init = tf.initialize_all_variables()
//One Session 
sess = tf.Session()
sess.run(init)
for i in range(1000):
  //쪼개서 여러번 돌림
  batch_xs, batch_ys = mnist.train.next_batch(100)
  sess.run(train_step, feed_dict={x: batch_xs, y_: batch_ys})
correct_prediction = tf.equal(tf.argmax(y,1), tf.argmax(y_,1))
accuracy = tf.reduce_mean(tf.cast(correct_prediction, tf.float32))
print(sess.run(accuracy, feed_dict={x: mnist.test.images, y_: mnist.test.labels}))
