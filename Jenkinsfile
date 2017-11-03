pipeline {
  agent any
  stages {
    stage('step2') {
      steps {
        isUnix()
        sh 'pwd'
        sh 'ls'
        sh './build.sh'
        sh 'ls'
      }
    }
  }
}