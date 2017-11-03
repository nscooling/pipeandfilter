pipeline {
  agent none
  stages {
    stage('build') {
      steps {
        echo 'simple pipeline'
      }
    }
    stage('step2') {
      steps {
        sh 'build.sh'
      }
    }
  }
}