pipeline {
  agent any
  stages {
    stage('build') {
      steps {
        echo 'simple pipeline'
      }
    }
    stage('step2') {
      steps {
        isUnix()
        sh 'build.sh'
      }
    }
  }
}