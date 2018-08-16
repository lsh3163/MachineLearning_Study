import os
os.environ['TF_CPP_MIN_LOG_LEVEL']='3'
import tensorflow as tf

##Dataset
x_train = [1,2,3]
y_train = [1,2,3]

## Weight 와 Bias 를 정의함
W = tf.Variable(tf.random_normal([1]),name='weight')
b = tf.Variable(tf.random_normal([1]),name='bias')

##Hypothesis를 정의함
hypothesis = W * x_train + b

##CostFunction을 정의함
cost = tf.reduce_mean(tf.square(hypothesis - y_train))

##train 한번에 cost 한번 최소화 (GradientDescentOptimizer)
optimizer = tf.train.GradientDescentOptimizer(learning_rate=0.01)
train = optimizer.minimize(cost)

##세션 실행
sess = tf.Session()
sess.run(tf.global_variables_initializer())

## 2000번 train
for step in range(2001):
    sess.run(train)
    if step % 20==0:
        print(step, sess.run(cost), sess.run(W),sess.run(b))
