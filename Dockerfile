FROM node:10.15.1
COPY package.json /app/package.json
RUN npm install -g bs-platform --unsafe-perm && apt-get update && apt-get install cron -y
WORKDIR /app
RUN npm install
EXPOSE 8001
# Add crontab file in the cron directory
ADD crontab /etc/cron.d/hello-cron

# Give execution rights on the cron job
RUN chmod 0644 /etc/cron.d/hello-cron

# Create the log file to be able to run tail
RUN touch /var/log/cron.log

#Install Cron
RUN apt-get update
RUN apt-get -y install cron
#RUN chmod 755 /script.sh /entry.sh
#RUN /usr/bin/crontab /crontab.txt
#COPY . ./
#RUN npm run build
#CMD ["npm","run","server"]